/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if(userName.empty())
    throw std::invalid_argument("Username is empty");
  if(!isalpha(userName.at(0)) || !islower(userName.at(0)))
    throw std::invalid_argument("Username does not start with a lowercase letter");
  for(int i = 1; i < static_cast<int>(userName.size()); i++)
  {
    if(isupper(userName.at(i)))
      throw std::invalid_argument("Username cannot contain uppercase letters");
  }
  this->userName = userName;
}

string User::getUserName() {
  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post == nullptr)
    throw std::invalid_argument("Nullptr");
  userPosts.push_back(post);
}
