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
													 , avatar_("")
													 , index_(0)
													 , bio_photo_indexs_("")
													 , email_("")
													 , rights_(Rights::Operator)


		{

		}
		BioPerson::BioPerson( int index
			                  , const std::string&    first_name
			                  , const std::string&    last_name
			                  , const Poco::DateTime& date_of_birth
			                  , Gender                gender
			                  , const std::string&    country
			                  , const std::string&    city
			                  , const std::string&    comments
			                  , const std::string&    avatar
												, const std::string&    bio_photo_indexs
												, const std::string&    email
												, Rights                rights)
												: index_(index)
												, first_name_(first_name)
			                  , last_name_(last_name)
			                  , date_of_birth_(date_of_birth)
			                  , gender_(gender)
			                  , country_(country)
			                  , city_(city)
			                  , comments_(comments)
			                  , avatar_(avatar)
												, bio_photo_indexs_(bio_photo_indexs)
												, email_(email)
												, rights_(rights)
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

		const std::string& BioPerson::avatar() const
		{
			return avatar_;
		}

		const std::string& BioPerson::bioPhotoIndexs() const
		{
			return bio_photo_indexs_;
		}

		const std::string& BioPerson::email() const
		{
			return email_;
		}

		Rights BioPerson::rights() const
		{
			return rights_;
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

		void BioPerson::setAvatar(const std::string& avatar)
		{
			avatar_ = avatar;
		}

		void BioPerson::setBioPhotoIndexs(const std::string& bio_photo_indexs)
		{
			bio_photo_indexs_ = bio_photo_indexs;
		}

		void BioPerson::setEmail(const std::string& email)
		{
			email_ = email;
		}

		void BioPerson::setRights(Rights rights)
		{
			rights_ = rights;
		}

		void BioPerson::setIndex(int index)
		{
			index_ = index;
		}
			

	}
}