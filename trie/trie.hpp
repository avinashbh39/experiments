#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <iostream>

namespace Util{

const int ALPHABETS_COUNT = 26;

struct Node{
	std::vector<Node*> childNodes;
	bool isWord;
	Node():childNodes(ALPHABETS_COUNT,nullptr),isWord(false){}
};

class Trie{
	public:
		Trie(){};

		bool FindWord(const std::string &word)
		{
			Node* currNode = &m_root;
			bool found = true ;
			for(auto letter:word)
			{
				auto asciiVal = letter - 'a';
				if((asciiVal >= 0 && asciiVal < ALPHABETS_COUNT) && !currNode->childNodes[asciiVal])
				{
					found = false;
					break;
				}
				currNode = currNode->childNodes[asciiVal];
			}	
			if(found)
				found = currNode->isWord ;

			return found ;		
		}

		void Insert(const std::string &word)
		{
			Node* currNode = &m_root;
			for(auto letter:word)
			{
				auto asciiVal = letter - 'a';
				if((asciiVal >= 0 && asciiVal < ALPHABETS_COUNT) && !currNode->childNodes[asciiVal])
				{
					currNode->childNodes[asciiVal] = new Node();
					
				}
				currNode = currNode->childNodes[asciiVal];
			}
			if(currNode != &m_root)
				currNode->isWord = true ;	
		}
	private:
		Node m_root ;
};
}
#endif //TRIE_HPP