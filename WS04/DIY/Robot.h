/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include <iostream>
namespace sdds
{
	class Robot
	{
		char* m_name;
		char* m_location;
		double m_weight;
		double m_width;
		double m_height;
		double m_speed;
		bool m_deployed;
	
	public:
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		~Robot();
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		Robot& setLocation(const char* location);
		Robot& setDeployed(const bool deployed);
		char* getName()const;
		char* getLocation()const;
		bool isDeployed()const;
		bool isValid()const;
		double speed()const;
		std::ostream& display()const;
	};
	int conrtolRooomReport(const Robot robot[], int num_robots);
	int numDeployed(const Robot robot[], int num_robots);
	void summary(const Robot robot[], int num_robots, int num_deployed);
	void border(int type);
	int fRobot(const Robot robot[], int num_robots);


}
#endif