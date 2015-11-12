#include "stdafx.h"
#include "bio_person_binder.hpp"


namespace Poco
{
	namespace Data
	{		
		//typedef BioPerson PersonType;
		typedef Poco::Data::TypeHandler<PersonType> BaseClass;

		
		void BaseClass::bind(std::size_t pos, const PersonType& obj
			                  , AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
		{
			poco_assert_dbg(!pBinder.isNull());

			pBinder->bind(pos++, obj.index()         , dir);
			pBinder->bind(pos++, obj.firstName()     , dir);
			pBinder->bind(pos++, obj.lastName()      , dir);
			pBinder->bind(pos++, obj.dateOfBirth()   , dir);
			pBinder->bind(pos++, obj.gender()        , dir);
			pBinder->bind(pos++, obj.country()       , dir);
			pBinder->bind(pos++, obj.city()          , dir);
			pBinder->bind(pos++, obj.avatar()        , dir);
			pBinder->bind(pos++, obj.bioPhotoIndexs(), dir);
			pBinder->bind(pos++, obj.email()         , dir);
			pBinder->bind(pos++, obj.comments()      , dir);
			pBinder->bind(pos++, obj.rights()        , dir);
		}


		void BaseClass::prepare(std::size_t pos, const PersonType& obj
			                     , AbstractPreparator::Ptr pPrepare)
		{
			 //no-op (SQLite is prepare-less connector)
		}

		std::size_t BaseClass::size()
		{
			return BaseClass::DATABASE_COLUMNS_SIZE;
		}

		void BaseClass::extract( std::size_t pos, PersonType& obj
			                     , const PersonType& defVal, AbstractExtractor::Ptr pExt)
		{

			poco_assert_dbg(!pExt.isNull());

			std::string    first_name       ;
			std::string    last_name        ;
			Poco::DateTime date_of_birth    ;			
			std::string    country          ;
			std::string    city             ;
			std::string    comments         ;
			std::string    avatar           ;	

			std::string    bio_photos_indexs;
			std::string    email            ;
			
			std::string date_of_birth_str;

			int gender;
			int index;
			int rights;

			if (pExt->extract(pos++, index))
				obj.setIndex(index);
			else
				obj.setIndex(defVal.index());

			if (pExt->extract(pos++, first_name))
				obj.setFirstName(first_name);
			else
				obj.setFirstName(defVal.firstName());

			if (pExt->extract(pos++, last_name))
				obj.setLastName(last_name);
			else
				obj.setLastName(defVal.lastName());

			if (pExt->extract(pos++, date_of_birth_str))
			{			
				int timezone;
				DateTimeParser::parse(DateTimeFormat::SORTABLE_FORMAT, date_of_birth_str, date_of_birth, timezone);
				obj.setDateOfBirth(date_of_birth);
			}
			else
				obj.setDateOfBirth(defVal.dateOfBirth());

			if (pExt->extract(pos++, gender))
				obj.setGender((SmartBio::Data::Gender)(gender));
			else
				obj.setGender(defVal.gender());

			if (pExt->extract(pos++, country))
				obj.setCountry(country);
			else
				obj.setCountry(defVal.country());

			if (pExt->extract(pos++, city))
				obj.setCity(city);
			else
				obj.setCity(defVal.city());

			if (pExt->extract(pos++, avatar))
				obj.setAvatar(avatar);
			else
				obj.setAvatar(defVal.avatar());

			if (pExt->extract(pos++, bio_photos_indexs))
				obj.setBioPhotoIndexs(bio_photos_indexs);
			else
				obj.setBioPhotoIndexs(defVal.bioPhotoIndexs());

			if (pExt->extract(pos++, email))
				obj.setEmail(email);
			else
				obj.setEmail(defVal.email());

			if (pExt->extract(pos++, comments))
				obj.setComments(comments);
			else
				obj.setComments(defVal.comments());

			if (pExt->extract(pos++, rights))
				obj.setRights((SmartBio::Data::Rights)(rights));
			else
				obj.setRights(defVal.rights());
		}

	}
}