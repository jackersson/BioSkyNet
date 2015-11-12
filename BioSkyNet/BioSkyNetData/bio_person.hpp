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

		enum Rights
		{
			  Manager = 0
			, Superviser
			, Operator
		};
	
		class BioPerson 
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
				       , const std::string&     avatar 
							 , const std::string&     bio_photo_indexs
							 , const std::string&     email
							 , Rights 						    rights);

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
				return avatar_;
			}

			
			const std::string&    firstName()       const;
			const std::string&    lastName()        const;
			Gender                gender()          const;
			const std::string&    country()         const;
			const std::string&    city()            const;
			const std::string&    avatar()          const;
			const std::string&    bioPhotoIndexs () const;
			const std::string&    email()           const;
			Rights                rights()          const;
			const std::string&    comments()        const;

			
			const Poco::DateTime& dateOfBirth()     const;

			int index() const;
			

		public:
			void setFirstName     (const std::string&    first_name      );
			void setLastName      (const std::string&    last_name       );
			void setGender        (Gender                gender          );
			void setDateOfBirth   (const Poco::DateTime& date_of_birth   );
			void setCountry       (const std::string&    country         );
			void setCity          (const std::string&    city            );
			void setComments      (const std::string&    comments        );
			void setAvatar        (const std::string&    avatar          );
			void setIndex         (int                   index           );
			void setBioPhotoIndexs(const std::string&    bio_photo_indexs);
			void setEmail         (const std::string&    email           );
			void setRights        (Rights                rights          );

			static const std::string& tableName()
			{
				static const std::string& table_name = "bio_subjects";
				return table_name;
			}
			
		private:
			std::string    first_name_      ;
			std::string    last_name_       ;
			Poco::DateTime date_of_birth_   ;
			Gender         gender_          ;
			std::string    country_         ;
			std::string    city_            ;
			std::string    comments_        ;
			std::string    avatar_		      ;
			std::string    bio_photo_indexs_;
			std::string    email_           ;
			Rights         rights_          ;

			int            index_           ;
			
			static bool initialized;
		};

	
	}
}

#endif

