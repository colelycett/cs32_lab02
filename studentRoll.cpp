#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  if (head == NULL) {
    head = new Node;
    head->s = new Student(s);
    head->next = NULL;
    tail = head;
    return;
  }

  tail->next = new Node;
  tail->next->s = new Student(s);
  tail->next->next = NULL;
  tail = tail->next;
  return;

}

std::string StudentRoll::toString() const {
  std::string rval = "[";
  Node* iter = head;
  while (iter != NULL) {
    rval += iter->s->toString();
    iter = iter->next;
    if (iter != NULL) {
      rval += ",";
    }
  }
  rval += "]";
  return rval;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {

  head = tail = NULL;
  Node* write = orig.head;
  while (write != NULL) {
    this->insertAtTail(*write->s);
    write = write->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* clear = head;
  while (clear != NULL) {
    Node* ahead = clear->next;
    delete clear;
    clear = ahead;
    if (ahead != NULL) {
      ahead = ahead->next;
    }
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





