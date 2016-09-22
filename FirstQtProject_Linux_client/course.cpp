#include "course.h"

Course::Course()
{
}


QString *Course::getCourseName() const
{
    return courseName;
}

void Course::setCourseName(QString *value)
{
    courseName = value;
}

void Course::addAssignement_id(const QString &value)
{
   assignement_id->append(value);
}


QList<QString> *Course::getAssignement_id() const
{
    return assignement_id;
}

void Course::setAssignement_id(QList<QString> *value)
{
    assignement_id = value;
}
QList<QString> *Course::getBranch() const
{
    return branch;
}

void Course::setBranch(QList<QString> *value)
{
    branch = value;
}

QList<QString> *Course::getAssignment_link() const
{
    return assignment_link;
}

void Course::setAssignment_link(QList<QString> *value)
{
    assignment_link = value;
}
void Course::addBranch(const QString &value)
{
    branch->append(value);
}


void Course::addAssignment_link(const QString &value)
{
    assignment_link->append(value);
}
