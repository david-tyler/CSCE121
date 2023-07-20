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
#include "Tag.h"
#include <cctype>

using std::string;
using std::vector;

Tag::Tag(string tagName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if(tagName.length() < 2)
    throw std::invalid_argument("Tag length is less than 2.");
  if(tagName.at(0) != '#')
    throw std::invalid_argument("First character of tagName is not '#'.");
  for(int i = 1; i < static_cast<int>(tagName.size()); i++)
  {
    if(!isalpha(tagName.at(i)))
    {
      throw std::invalid_argument("Only letters allowed.");
    }
    if(isupper(tagName.at(i)))
    {
      throw std::invalid_argument("Only lowercase letters allowed.");
    }
  }
  if(tagName.at(tagName.length() - 1) == '!' || tagName.at(tagName.length() - 1) == ',' || tagName.at(tagName.length() - 1) == '.' || tagName.at(tagName.length() - 1) == '?')
  {
    throw std::invalid_argument("No punctuation allowed.");
  }

  this->tagName = tagName;
  
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if(post == nullptr)
    throw std::invalid_argument("Nullptr");
  else
  {
    tagPosts.push_back(post);

  }
  
}
