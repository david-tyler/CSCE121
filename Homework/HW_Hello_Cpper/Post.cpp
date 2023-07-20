/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"
#include <cctype>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  vector<string> tags;
  std::stringstream ss;
  string copy_postText = getPostText();
  ss.str(copy_postText);
  string word;
  while(ss >> word)
  {
    if(word.at(0) == '#')
    {
      for(unsigned long i = 1; i < word.length(); i++)
      {
        word[i] = tolower(word[i]);
      }
      int i = word.length()-1;
      while(i >= 0)
      {
        if(word[i] == '!' || word[i] == ',' || word[i] == '.' || word[i] == '?')
        {
          word.pop_back();
        }
        else
        {
          i--;
        }
      }
      tags.push_back(word);
    }
    
  }
  
  return tags;

}
