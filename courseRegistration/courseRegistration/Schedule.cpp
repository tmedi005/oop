#include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

/**
 *
 */
Schedule::Schedule()
    :head(nullptr),
     tail(nullptr)

{
   totalCredits = 0;
}


Schedule::Schedule(const Schedule& src)
    :head(nullptr),
    tail(nullptr),
    totalCredits(0)
{
    Node* it = src.head;

    while (it != nullptr) {
        this -> add(it->data);

        it = it->next;
    }

}

Schedule::~Schedule() {

    Node* it = this->head;

    while (it != nullptr)
    {
        Node * prev = it;

        it = it->next;
        delete prev;
    }
    it = nullptr;
    this->head = nullptr;
    this->tail = nullptr;

}


bool Schedule::add(Course course)
{
    if ( totalCredits + course.getCredits() > 15 ) {
    return false;
}

Node* it = head;

while (it != nullptr) {
    if (course == it->data) {
        return false;
    }
    it = it->next;
}

it = nullptr;


    Node* newNode = new Node(course);


    if (head == nullptr) {
        head        = newNode;
        tail        = newNode;
        totalCredits  += course.getCredits();


        newNode     = nullptr;

        return true;
    }



    tail->next = newNode;


    tail = tail->next;



    totalCredits  += course.getCredits();
    return true;


}


void Schedule::display(std::ostream& outs) const
{


    Node *it = head;

   while (it!=nullptr){
        outs<<"  - "<<it->data<<"\n";
       it = it->next;

    }

    it = nullptr;
        outs<<"  ("<<totalCredits<<" Total Credits)""\n";

}

Schedule& Schedule::operator=(const Schedule& rhs)
{
     if (this != &rhs)
        {

            Node* it = this->head;

            while (it != nullptr)
                {
                    Node* prev = it;

                    it = it->next;
                    delete prev;
                }
            it = nullptr;

            this->head = nullptr;
            this->tail = nullptr;


            this->totalCredits = rhs.totalCredits;


            it = rhs.head;

            while (it != nullptr)
                {
                    this->add(it->data);
                    it = it->next;
                }
    }

    return *this;
}
