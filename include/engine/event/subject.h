#ifndef _SUBJECT_H
#define _SUBJECT_H

#include "engine/event/observer.h"

class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}
    virtual void notify() = 0;
};

#endif