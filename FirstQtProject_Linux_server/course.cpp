#include "course.h"

Course::Course()
{
    this->assignment_id = new QList<QString>();
    this->assignment_link = new QList<QString>();
    this->branch = new QList<QString>();
    this->studentsEnroled = new QList<QString>();
}

Course::Course(QString courseName)
{
    this->courseName = new QString(courseName);
    this->assignment_id = new QList<QString>();
    this->assignment_link = new QList<QString>();
    this->branch = new QList<QString>();
    this->studentsEnroled = new QList<QString>();

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
   assignment_id->append(value);
}


QList<QString> *Course::getAssignement_id() const
{
    return assignment_id;
}

void Course::setAssignement_id(QList<QString> *value)
{
    assignment_id = value;
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


QList<QString> *Course::getStudentsEnroled() const
{
    return studentsEnroled;
}

void Course::setStudentsEnroled(QList<QString> *value)
{
    studentsEnroled = value;
}
