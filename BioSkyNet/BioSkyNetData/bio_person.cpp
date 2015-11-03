#include "stdafx.h"
#include "bio_person.hpp"

namespace SmartBio
{
	namespace Data
	{
		BioPerson::BioPerson() : first_name_("")
			                     , last_name_("")
													 , date_of_birth_()
			                     , gender_(Gender::Male)
			                     , country_("")
			                     , city_("")
			                     , comments_("")
													 , photo_path_("")
													 , index_(0)

		{

		}
		BioPerson::BioPerson( int index
			                  , const std::string&    first_name
			                  , const std::string&    last_name
			                  , const Poco::DateTime& date_of_birth
			                  , Gender         gender
			                  , const std::string&   country
			                  , const std::string&    city
			                  , const std::string&    comments
			                  , const std::string&    photo_path)
												: index_(index)
												, first_name_(first_name)
			                  , last_name_(last_name)
			                  , date_of_birth_(date_of_birth)
			                  , gender_(gender)
			                  , country_(country)
			                  , city_(city)
			                  , comments_(comments)
			                  , photo_path_(photo_path)
		{

		}

		BioPerson::~BioPerson() {}


		const std::string& BioPerson::firstName() const
		{
			return first_name_;
		}

		const std::string&    BioPerson::lastName() const
		{
			return last_name_;
		}

		Gender BioPerson::gender() const
		{
			return gender_;
		}

		const std::string& BioPerson::country() const
		{
			return country_;
		}

		const std::string& BioPerson::city() const
		{
			return city_;
		}

		const std::string& BioPerson::photoPath() const
		{
			return photo_path_;
		}

		const std::string& BioPerson::comments() const
		{
			return comments_;
		}

		int BioPerson::index() const
		{
			return index_;
		}

		const Poco::DateTime& BioPerson::dateOfBirth() const
		{
			return date_of_birth_;
		}

		void BioPerson::setFirstName(const std::string& first_name)
		{
			first_name_ = first_name;
		}

		void BioPerson::setLastName(const std::string& last_name)
		{
			last_name_ = last_name;
		}

		void BioPerson::setGender(Gender gender)
		{
			gender_ = gender;
		}

		void BioPerson::setDateOfBirth(const Poco::DateTime& date_of_birth)
		{
			date_of_birth_ = date_of_birth;
		}

		void BioPerson::setCountry(const std::string& country)
		{
			country_ = country;
		}

		void BioPerson::setCity(const std::string& city)
		{
			city_ = city;
		}

		void BioPerson::setComments(const std::string& comments)
		{
			comments_ = comments;
		}

		void BioPerson::setPhotoPath(const std::string& photo_path)
		{
			photo_path_ = photo_path;
		}

		void BioPerson::setIndex(int index)
		{
			index_ = index;
		}
			

	}
}