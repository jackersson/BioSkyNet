#include "stdafx.h"
//#include "database_logger.hpp"

//#include "bio_person_binder.hpp"
#include "bio_person_db_io.hpp"
#include <time.h>

using namespace SmartBio::Data;

int main()
{

	/*try
	{*/
		std::string address = "F:\\SmartProjects\\SmartBio\\SmartBio\\database\\smart_biometrics.db";
		BioPersonDbIO bio(address);
		

		std::string    first_name = "Taras";
		std::string    last_name = "Lishchenko";
		Poco::DateTime date_of_birth = Poco::DateTime(1992, 10, 16);
		std::string    country = "Ukraine";
		std::string    city = "Vinnytsia";
		std::string    comments = "Comments";
		std::string    photo_path = "taras.jpg";
		SmartBio::Data::Gender gender = SmartBio::Data::Gender::Male;

		std::string date_of_birth_str;

		SmartBio::Data::BioPerson p1(0, first_name, last_name, date_of_birth, gender
			, country, city, comments, photo_path);
		

		clock_t begin = clock();
		bio.write(p1);	
		std::cout <<  clock() - begin << " = time" << std::endl;
/*

	
		std::string address = "F:\\SmartProjects\\SmartBio\\SmartBio\\database\\smart_biometrics.db";
		//std::string address = "F:\\SmartProjects\\SmartBio\\SmartBio\\database\\bioskynet.db";
		Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, address);

		std::cout << tmp.isConnected() << std::endl;

		std::string    first_name = "Taras";
		std::string    last_name = "Lishchenko";
		Poco::DateTime date_of_birth = Poco::DateTime(1992, 10, 16);
		std::string    country = "Ukraine";
		std::string    city = "Vinnytsia";
		std::string    comments = "Comments";
		std::string    photo_path = "taras.jpg";
		SmartBio::Data::Gender gender = SmartBio::Data::Gender::Male;

		std::string date_of_birth_str;

		
		std::string tableName("bio_subjects");
		std::string result;

		/ *	tmp << "DROP TABLE IF EXISTS Simpsons", now;
			tmp << "CREATE TABLE IF NOT EXISTS Simpsons (LastName VARCHAR(30), FirstName VARCHAR, Address VARCHAR, Age INTEGER(3))", now;
			tmp << "SELECT name FROM sqlite_master WHERE tbl_name=?", use(tableName), into(result), now;

			std::cin.get();

			return 0;*	//	tmp << "DROP TABLE IF EXISTS bio_subjects", now;* /

		int max = 0;
		tmp << "SELECT max(Id) FROM bio_subjects", into(max), now;

		SmartBio::Data::BioPerson p1( ++max, first_name, last_name, date_of_birth, gender
			, country, city, comments, photo_path);

		std::vector<std::string> query;

		query.push_back("CREATE TABLE IF NOT EXISTS [bio_subjects]");
		query.push_back(" ( ");
		query.push_back(" Id INTEGER PRIMARY KEY ");
		query.push_back(" , FirstName ntext NOT NULL");
		query.push_back(" , LastName ntext NOT NULL");
		query.push_back(" , DateOfBirth datetime NOT NULL");
		query.push_back(" , Gender tinyint NOT NULL");
		query.push_back(" , Country ntext NOT NULL");
		query.push_back(" , City ntext NOT NULL");
		query.push_back(" , Photo ntext NOT NULL");
		query.push_back(" , Comment ntext NOT NULL");
		//query.push_back(" , CONSTRAINT[PK_bio_subjects] PRIMARY KEY([Id])");
		query.push_back(" );");

			 
		std::string squery = Poco::cat(std::string(""), query.begin(), query.end());

		std::cout << squery << std::endl;
		tmp << squery, now;

		
		tmp << "INSERT INTO bio_subjects VALUES( :id, :fn, :ln, :db, :gn, :cn, :ct, :cm, :ph )", use(p1), now;


		std::set<SmartBio::Data::BioPerson> db_persons;
		tmp << "SELECT * FROM bio_subjects", into(db_persons), now;

		for (auto it = db_persons.begin(); it != db_persons.end(); ++it)
		{
			std::cout << (*it).firstName() << std::endl;
		}

		
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
*/

	std::cin.get();
	return 0;
}