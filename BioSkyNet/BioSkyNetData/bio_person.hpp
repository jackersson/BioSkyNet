#ifndef Bio_Person_INCLUDED
#define Bio_Person_INCLUDED

#include "idatabase_io.hpp"


namespace SmartBio
{
	namespace Data
	{		
		enum Gender
		{
			  Male = 0
			, Female
			, Undefined
		};
	
		class BioPerson //: public Interfaces::IDatabaseIO
		{
		public:
			BioPerson();

			BioPerson( int id
				       , const std::string&     first_name
				       , const std::string&     last_name
				       , const Poco::DateTime&  date_of_birth
				       , Gender                 gender
				       , const std::string&     country
				       , const std::string&     city
				       , const std::string&     comments
				       , const std::string&     photo_path);

			virtual ~BioPerson();

			bool operator==(const BioPerson& other) const
			{
				return    first_name_    == other.firstName()
					     && gender_        == other.gender()
					     && last_name_     == other.lastName()
					     && date_of_birth_ == other.dateOfBirth();
				
			}

			bool operator < (const BioPerson& p) const
			{
				if (index_ < p.index())
					return true;
				else
					return false;
			}

			const std::string& operator() () const			
			{				
				return photo_path_;
			}

			
			const std::string&    firstName() const;
			const std::string&    lastName()  const;
			Gender                gender()    const;
			const std::string&    country()   const;
			const std::string&    city()      const;
			const std::string&    photoPath() const;
			const std::string&    comments () const;
			
			const Poco::DateTime& dateOfBirth() const;

			int index() const;

			//bool write(Poco::Data::Session& session);
			//bool read (Poco::Data::Session& session);


		public:
			void setFirstName  (const std::string& first_name);
			void setLastName   (const std::string& last_name );
			void setGender     (Gender gender);
			void setDateOfBirth(const Poco::DateTime& date_of_birth);
			void setCountry    (const std::string& country);
			void setCity       (const std::string& city);
			void setComments   (const std::string& comments);
			void setPhotoPath  (const std::string& photo_path);
			void setIndex      (int index);
		private:
			std::string    first_name_   ;
			std::string    last_name_    ;
			Poco::DateTime date_of_birth_;
			Gender         gender_       ;
			std::string    country_      ;
			std::string    city_         ;
			std::string    comments_     ;
			std::string    photo_path_   ;

			int    index_;
			
	
		};

	
	}
}

#endif

