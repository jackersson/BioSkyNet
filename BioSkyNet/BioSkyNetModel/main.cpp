#include "stdafx.h"

#include "bio_model.hpp"

using namespace SmartBio::Model;
using namespace SmartBio::Data ;

int main()
{
	Poco::SharedPtr<BioModel> model = BioModel::instance(); 

	std::string    first_name = "Taras";
	std::string    last_name = "Lishchenko";
	Poco::DateTime date_of_birth = Poco::DateTime(1992, 10, 16);
	std::string    country = "Ukraine";
	std::string    city = "Vinnytsia";
	std::string    comments = "Comments";
	std::string    avatar = "taras.jpg";
	std::string    bio_photo_indexes = "1123, 1241, 124";
	std::string    email = "jackersson@meta.ua";
	SmartBio::Data::Rights    rights = SmartBio::Data::Rights::Manager;


	SmartBio::Data::Gender gender = SmartBio::Data::Gender::Male;

	std::string date_of_birth_str;

	SmartBio::Data::BioPerson p1( 0, first_name, last_name, date_of_birth, gender
		                          , country, city, comments, avatar
		                          , bio_photo_indexes, email, rights);

	//std::vector<BioPerson> vec;
	model->databaseEngine()->write<BioPerson>(p1);
	return 0;
}
