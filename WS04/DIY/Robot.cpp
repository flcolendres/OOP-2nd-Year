/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Robot.h"
#include"Utils.h"
using namespace std;
namespace sdds
{


	Robot::Robot()
	{
		m_name = nullptr;
		m_location = nullptr;
		resetVal(&m_weight, &m_width, &m_height, &m_speed, &m_deployed);
	}

	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		m_name = new char[strlen(name) + 1];
		m_location = new char[strlen(location) + 1];
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
		resetVal(&m_weight, &m_width, &m_height, &m_speed, &m_deployed);
	}

	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		delete[] m_name;
		delete[] m_location;
		m_name = new char[strlen(name) + 1];
		m_location = new char[strlen(location) + 1];
		strcpy(m_name, name);
		setLocation(location);
		m_weight = weight;
		m_width = width;
		m_height = height;
		m_speed = speed;
		setDeployed(deployed);
		return *this;
	}

	Robot& Robot::setLocation(const char* location)
	{
		strcpy(m_location, location);
		return *this;
	}

	Robot& Robot::setDeployed(const bool deployed)
	{
		m_deployed = deployed;
		return *this;
	}

	char* Robot::getName() const
	{
		return m_name;
	}

	char* Robot::getLocation() const
	{
		return m_location;
	}

	bool Robot::isDeployed() const
	{
		return m_deployed;
	}

	bool Robot::isValid() const
	{
		bool result = true;
		if (m_name == nullptr || m_location == nullptr || m_weight <= 0 || m_width <= 0 || m_height <= 0 || m_speed <= 0)
			result = false;

		return result;
	}

	double Robot::speed() const
	{
		return m_speed;
	}

	ostream& Robot::display() const
	{
		cout.setf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << "| ";
		cout.width(11);
		cout << m_name << "| ";
		cout.width(16);
		cout << m_location << "| ";
		cout.unsetf(ios::left);
		cout.width(6);
		cout << m_weight << " |";
		cout.width(7);
		cout << m_width << " |";
		cout.width(7);
		cout << m_height << " |";
		cout.width(7);
		cout << m_speed << " | ";
		cout.setf(ios::left);
		cout.width(9);
		cout << (m_deployed == true ? "YES" : "NO");
		cout << "|" << endl;
		cout.unsetf(ios::left);
		return cout;
	}

	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int i, result = -1;
		border(1);
		border(2);
		for (i = 0; i < num_robots && result == -1; i++)
		{
			if (robot[i].isValid())
				robot[i].display();
			else
				result = i;
		}
		if (i == num_robots)
		{
			summary(robot, num_robots, numDeployed(robot, num_robots));
		}
		return result;
	}
	int numDeployed(const Robot robot[], int num_robots)
	{
		int i, num = 0;
		for (i = 0; i < num_robots; i++)
		{
			if (robot[i].isDeployed())
				num++;
		}
		return num;
	}
	void summary(const Robot robot[], int num_robots, int num_deployed)
	{
		int i, fRobot = 0;
		double speed;

		for (i = 0, speed = 0; i < num_robots; i++)
		{
			if (robot[i].isDeployed())
			{
				if (robot[i].speed() > speed)
				{
					speed = robot[i].speed();
					fRobot = i;
				}

			}
		}
		border(3);
		cout.setf(ios::left);
		cout.width(78);
		cout << "| SUMMARY:"<< "|" << endl;
		cout << "| " << num_deployed << "  robots are deployed.";
		cout.unsetf(ios::left);
		cout.width(54);
		cout << "|" << endl;
		cout << "| The fastest robot is:";
		cout.width(56);
		cout << "|" << endl;
		border(2);
		robot[fRobot].display();
		border(3);

	}

	void border(int type)
	{
		switch (type)
		{
		case 1:
			cout.width(57);
			cout << "------ Robot Control Room -----" << endl;
			cout.width(59);
			cout << "---------------------------------------" << endl;
			break;
		case 2:
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			break;
		case 3:
			cout.setf(ios::left);
			cout.width(78);
			cout.fill('=');
			cout << "|" << "|" << endl;
			cout.fill(' ');
			cout.unsetf(ios::left);
			break;
		}
	}

}