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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"
#include "User.h"
#include <cctype>


using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream inFS;
  inFS.open(fileName);

  if(!inFS.is_open())
  {
    throw std::invalid_argument("File could not be opened.");
  }
  try
  {
    string line;
    while(getline(inFS, line))
    {
      string type;
      string username;
      string post_text;
      unsigned int postID;
      std::stringstream ss;
      ss << line;
      ss >> type;

      if(type == "User")
      {
        ss >> username;
        addUser(username);
      }
      if(type == "Post")
      {
        ss >> postID;
        ss >> username;
        string word;
        while(ss >> word)
        {
          post_text += " " + word;
        }
        post_text.erase(0, 1);
        addPost(postID, username, post_text);
      }
      if(type != "User" && type != "Post")
      {
        throw std::runtime_error("File does not match specified format.");
      }
    }
  }
  catch(...)
  {
    throw std::runtime_error("File does not match specified format.");
  }
  inFS.close();
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network

  
    for(int i = 0; i < static_cast<int>(userName.size()); i++)
    {
      userName.at(i) = tolower(userName.at(i));
    }
    for(int i = 0; i < static_cast<int>(users.size()); i++)
    {
      if(userName == users.at(i)->getUserName())
      {
        throw std::invalid_argument("Invalid");
      }
    }
    User* new_user = new User(userName);
    users.push_back(new_user);

    std::cout << "Added User " << userName << std::endl;
  
  

}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  for(int i = 0; i < posts.size(); i++)
  {
    if(posts.at(i)->getPostId() == postId)
    {
      throw std::invalid_argument("PostId already exists.");
    }
  }
  bool foundUser = false;
  int indexFound = 0;
  for(int i = 0; i < users.size(); i++)
  {
    if(users.at(i)->getUserName() == userName)
    {
      indexFound = i;
      foundUser = true;
    }
  }
  if(foundUser == false)
  {
    throw std::invalid_argument("User was not found.");
  }

  Post* new_post = new Post(postId, userName, postText);
  posts.push_back(new_post);
  users.at(indexFound)->addUserPost(new_post);
  
  vector<string> new_tags = new_post->findTags();
  
  for(unsigned long i = 0; i < new_tags.size(); i++)
  {
    bool foundTag = false;
    for(unsigned long j = 0; j < tags.size(); j++)
    {
      if(new_tags[i] == tags[j]->getTagName())
      {
        foundTag = true;
        tags[j]->addTagPost(new_post);
      }
    }
    try
    { 
      if(foundTag == false)
      {
        Tag *new_tag = new Tag(new_tags[i]);
        tags.push_back(new_tag);
        tags.back()->addTagPost(new_post);  
      }
    }
    catch(std::exception& e)
    {

    }
  }
  std::cout << "Added Post " << postId << " by " << userName << std::endl;
  
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if(userName == "")
  {
    throw std::invalid_argument("Username is empty");
  }
  for(unsigned long i=0; i < users.size(); i++)
  {
    if(users.at(i)->getUserName() == userName)
    {
      return users.at(i)->getUserPosts();
    }
  }
  throw std::invalid_argument("User not found.");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  vector<Post*> postsWTag;
  if(tagName == "")
  {
    throw std::invalid_argument("Username is empty");
  }
  for(unsigned long i=0; i < tags.size(); i++)
  {
    if(tags.at(i)->getTagName() == tagName)
    {
      return tags.at(i)->getTagPosts();
    }
  }
  throw std::invalid_argument("Tag name not found.");
  return postsWTag;
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  vector<string> pop_tags;
  unsigned long most = 0;
  for(unsigned long i=0; i < tags.size(); i++)//Because there could be multiple with the same amount we cannot just simply find the max once and add only one, we need to add all of the most popular so we just find what the greatest size is and in the second loop and compare which ones match that size
  {
    
    if(tags.at(i)->getTagPosts().size() > most)
    {
      
      most = tags.at(i)->getTagPosts().size();
    }
  }
  for(unsigned long i=0; i < tags.size(); i++)
  {
    if(tags.at(i)->getTagPosts().size() == most)
    {
      pop_tags.push_back(tags.at(i)->getTagName());
    }
  }
  return pop_tags;

}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
