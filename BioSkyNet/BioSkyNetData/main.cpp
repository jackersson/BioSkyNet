#include "stdafx.h"

//#include "bio_person_db_io.hpp"
#include "bio_visitor_binder.hpp"
#include "bio_photo_item_binder.hpp"
#include "bio_location_binder.hpp"

#include "bio_db_io.hpp"


#include <time.h>

using namespace SmartBio::Data;
using namespace Poco::Data::Keywords;
int main()
{
	std::string address = "D:\\Spark\\BioSkyNet\\BioSkyNet\\BioSkyNetData\\dataBase\\bioskynet.db";	

	std::string    first_name = "Taras";
	std::string    last_name = "Lishchenko";
	Poco::DateTime date_of_birth = Poco::DateTime(1992, 10, 16);
	std::string    country = "Ukraine";
	std::string    city = "Vinnytsia";
	std::string    comments = "Comments";
	std::string    avatar = "taras.jpg";
	std::string    bio_photo_indexes = "1123, 1241, 124";
	std::string    email             = "jackersson@meta.ua";
	SmartBio::Data::Rights    rights = SmartBio::Data::Rights::Manager;

	
	SmartBio::Data::Gender gender = SmartBio::Data::Gender::Male;

	std::string date_of_birth_str;

	SmartBio::Data::BioPerson p1(0, first_name, last_name, date_of_birth, gender
		                          , country, city, comments, avatar
															, bio_photo_indexes, email, rights);

	std::string person = "1,2,3";
	std::string photo = "4,5,6";
	std::string path = "path";
	std::string location = "7,8,9";
	
	

	SmartBio::Data::BioVisitor p2(0, person, photo, 3
		, path
		, date_of_birth, location, SmartBio::Data::Status::Deny);

	std::string photo_path = "231";
	std::string fir = "543";
	std::string res = "658";


	SmartBio::Data::Etnicity etnicity = SmartBio::Data::Etnicity::White;
	

	SmartBio::Data::BioPhotoItem p3(0, photo_path, fir, 3
		                             , gender
		                             , 10, true, res, etnicity);

	std::string loc_name = "231";
	std::string port_name = "dfgh";
	std::string email_notif = "yfshdj";
	std::string camera_name = "prokgef";


	SmartBio::Data::BioLocation p4(0, loc_name, port_name, email_notif
		, camera_name
		, 10, 0.1f, 0.2f, 0.3f, 0.4f);
	

	Poco::SharedPtr<BioDbIO> db_io = new BioDbIO(address);
	std::vector<BioPerson> vec;
	db_io->read<BioPerson, BioPersonTable>(vec, "");

	std::cout << vec.size() << std::endl;

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << " First Name : " << (*it).firstName() << std::endl;
		std::cout << " Last  Name : " << (*it).lastName()  << std::endl;
	}
	//db_io->write<BioLocation   , BioLocationTable>(p4);
	//db_io->write<BioPhotoItem  , BioPhotoItemTable>(p3);
	//db_io->write<BioVisitor    , BioVisitorTable>(p2);




	std::cin.get();
	return 0;
}