/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
	class Robots
	{
		char* m_name;
		char* m_location;
		double m_weight;
		double m_width;
		double m_height;
		double m_speed;
		bool m_deployed;
	
	public:
		Robots();
		Robots(char& name, char& location, double weight, double width, double height, double speed, bool deployed);
		~Robots();
		Robots& set(char& name, char& location, double weight, double width, double height, double speed, bool deployed);
		Robots& setLocation();
		Robots& setDeployed();
		void getName()const;
		void getLocation()const;
		bool isDeployed()const;
		bool isValid()const;


	};



}
#endif