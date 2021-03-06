#ifndef COURSE_H
#define COURSE_H
#include<QList>
#include<QString>

class Course
{
public:
    Course();
    Course(QString courseName);

    void addProjects(const QString value);

    QString *getCourseName() const;
    void setCourseName(QString *value);    

    void addAssignement_id(const QString &value);


    void addAssignment_link(const QString &value);


    void addBranch(const QString &value);

    QList<QString> *getAssignement_id() const;
    void setAssignement_id(QList<QString> *value);

    QList<QString> *getAssignment_link() const;
    void setAssignment_link(QList<QString> *value);

    QList<QString> *getBranch() const;
    void setBranch(QList<QString> *value);

    QList<QString> *getStudentsEnroled() const;
    void setStudentsEnroled(QList<QString> *value);


private:
    QString *courseName;
    QList<QString> *assignment_id;
    QList<QString> *assignment_link;
    QList<QString> *branch;
    QList<QString> *studentsEnroled;
};

#endif // Course_H
