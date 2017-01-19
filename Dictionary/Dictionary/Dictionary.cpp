#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<vector>
#include"Trie.h"

using namespace std;

bool isValidSeparator(char s)
{
	return (s == ' ' || s == '\n' || s == '\t');
}

int main(int argc, char** argv)
{
	Trie Dictionary = Trie();
	ifstream file(argv[1]);
	string line;
	string word;
	vector<string> words;

	//Reading Dictionary and adding words
	
	while (getline(file, line))
	{
		// Get line and split it
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line[i] != ' ')
			{
				word += line[i];
			}
			else
			{
				if (word != "")
				{
					words.push_back(word);
					word = "";
				}
			}
			if (i == line.length() - 1)
			{
				words.push_back(word);
				word = "";
			}
		}

		if (words.size() == 2)
		{
			Node* current = Dictionary.FindWord(words[0], Dictionary.GetRoot());
			if (current == NULL)
			{
				Dictionary.AddAsRootChild(words[0], stod(words[1]));
			}
			else
			{
				current->SetMark(stod(words[1]));
			}
		}
		else
		{
			Node* current = Dictionary.FindWord(words[0], Dictionary.GetRoot());
			Node* parent;
			if (current == NULL)
			{
				parent = Dictionary.AddAsRootChild(words[0], 0);
			}
			else
			{
				parent = current;
			}
			for (size_t j = 1; j < words.size(); j++)
			{
				if (!isdigit(words[j][0]))
				{
					if (isdigit(words[j + 1][0]) || words[j + 1][0] == '-')
					{
						current = Dictionary.FindWord(words[j], parent);
						if (current == NULL)
						{
							Dictionary.AddWord(words[j], stod(words[j + 1]), parent);
						}
						else
						{
							current->SetMark(stod(words[j + 1]));
							parent = current;
						}
						break;
					}
					else
					{
						current = Dictionary.FindWord(words[j], parent);
						if (current == NULL)
						{
							parent = Dictionary.AddWord(words[j], 0, parent);
						}
						else
						{
							parent = current;
						}
					}

				}
			}
		}

		words.clear();
	}
	file.close();

	//Reading texts and calculating marks
	int numberFile = 2;
	double sum = 0;
	int wordsCount = 0;

	while (numberFile < argc)
	{
		ifstream file(argv[numberFile]);
		char c;
		string extractedWord = "";
		int wordInSequence = 0;
		double mark = 0;
		streampos currentPosInText;
		int numberOfSeparators = 0;
		streampos lastWord;

		Node* parent = new Node();
		bool isSymbol = false;
		bool isBroken = false;
		double smark = 0;
		string emptySpace = "";
		while (file.get(c))
		{
			//Get a word
			if (isalpha(c))
			{
				extractedWord += tolower(c);
			}
			else if (extractedWord != "") //When the word is got and is not empty
			{
				wordsCount++; //increase number of words in text

				if (wordInSequence < 1 || (wordInSequence > 0 && (isSymbol || numberOfSeparators > 1))) //if this is the first word in current sequence or can't be phrase
				{
					if (wordInSequence > 1)
					{
						sum += mark;
					}
					parent = Dictionary.FindWord(extractedWord, Dictionary.GetRoot()); //Search a word in root's children
					if (parent != NULL) //if a word is found
					{
						wordInSequence++; //increase number of words in current sequence
						mark = parent->GetMark(); //get the mark of word
					}
					else
					{
						wordInSequence = 0; //set begin of new sequence
					}
				}
				else //if this is not the first word in current sequence
				{
					parent = Dictionary.FindWord(extractedWord, parent); //Search a word in previous word's children
					if (parent != NULL) //if a word is found
					{
						wordInSequence++; //increase number of words in current sequence
						mark = parent->GetMark(); //get the mark of word
						if (mark != 0)
						{
							lastWord = (int)file.tellg();
							cout << (int)lastWord << endl;
							smark = mark;
						}
					}
					else
					{
						sum += mark; //increase the sum with mark of max-length-sequence
						wordInSequence = 0; //set begin of new sequence
						isBroken = true;

						//parent = Dictionary.FindWord(extractedWord, Dictionary.GetRoot()); //Search a word in root's children
						//if (parent != NULL)
						//{
						//	mark = parent->GetMark(); //get the mark of word
						//	wordInSequence++; //increase number of words in current sequence
						//}
					}

				}
				isSymbol = false;
				numberOfSeparators = 0;

				if (!isBroken)
				{
					//Check if the space between extractedWord and next word has invallid separatorsin phrase
					while (!isalpha(c) && !file.eof())
					{
						emptySpace += c;
						if (isValidSeparator(c))
						{
							numberOfSeparators++;
						}
						else
						{
							isSymbol = true;
						}
						file.get(c);
					}
					currentPosInText = (int)file.tellg() - 1;
					file.seekg(currentPosInText, ios::beg);


				}
				else if (isBroken && smark != 0)
				{
					sum += smark;
					file.seekg(lastWord, ios::beg);
					isBroken = false;
					smark = 0;
					wordInSequence = 0;
				}
				

				extractedWord = "";
			}
		}

		cout << argv[numberFile] << " " << sum << endl;
		numberFile++;
		sum = 0;
	}


	system("pause");
	return 0;
}