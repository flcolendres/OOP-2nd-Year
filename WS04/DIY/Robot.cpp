/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Robot.h"
#include"Utils.h"
using namespace std;
namespace sdds
{


	Robot::Robot()
	{
		resetVal(m_name, m_location, &m_weight, &m_width, &m_height, &m_speed, &m_deployed);
	}

	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		m_name = new char[MAX_CHAR + 1];
		m_location = new char[MAX_CHAR + 1];
		strcpy(m_name, name);
		strcpy(m_location, location);
		m_weight = weight;
		m_width = width;
		m_height = height;
		m_speed = speed;
		m_deployed = deployed;
	}

	Robot::~Robot()
	{
		delete[] m_name;
		delete[] m_location;
		resetVal(m_name, m_location, &m_weight, &m_width, &m_height, &m_speed, &m_deployed);
	}

	Robot& Robot::set(char& name, char& location, double weight, double width, double height, double speed, bool deployed)
	{

		return *this;
	}

	Robot& Robot::setLocation()
	{
		return *this;
	}

	Robot& Robot::setDeployed()
	{
		return *this;
	}

	void Robot::getName() const
	{
	}

	void Robot::getLocation() const
	{
	}

	bool Robot::isDeployed() const
	{
		return false;
	}

	bool Robot::isValid() const
	{
		return false;
	}

	ostream& Robot::display()
	{

		return cout;
	}


}