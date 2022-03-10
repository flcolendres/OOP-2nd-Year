/* ------------------------------------------------------
Final project Milestone 1
Module: Status
Filename: Status.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-08
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
namespace sdds
{
   class Status
   {
      char* m_errDesc;
      int m_errCode;
   public:
      Status(const char* c = nullptr);
      Status(const Status& s);
      Status& operator=(const Status& s);
   };

}
#endif