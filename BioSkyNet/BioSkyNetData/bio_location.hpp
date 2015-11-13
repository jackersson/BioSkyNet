#ifndef Bio_Location_INCLUDED
#define Bio_Location_INCLUDED

#include "idatabase_io.hpp"


namespace SmartBio
{
	namespace Data
	{


		class BioLocation
		{
		public:
			BioLocation();

			BioLocation( int index
				         , const std::string&  location_name
				         , const std::string&  port_name
				         , const std::string&	 email_notification
				         , const std::string&  camera_name
				         , int                 age_treshold
				         , float               face_confidence
				         , float               min_eye_distance
				         , float               max_eye_distance
				         , float               matching_treshold  );

			virtual ~BioLocation();

			bool operator==(const BioLocation& other) const
			{
				return    index_ == other.index();


			}

			bool operator < (const BioLocation& p) const
			{
				if (index_ < p.index())
					return true;
				else
					return false;
			}

			const std::string& operator() () const
			{
				return location_name_;
			}


			const std::string&   location_name()       const;
			const std::string&   port_name()           const;
			const std::string&   email_notification()  const;
			const std::string&   camera_name()         const;
			int                  age_treshold()        const;
			float                face_confidence()     const;
			float                min_eye_distance()    const;
			float                max_eye_distance()    const;
			float								 matching_treshold()   const;
			int                  index()               const;

			const std::vector<int>&   personIndexs()   const;

		public:
			void setLocationName     (const std::string& location_name_     );
			void setPortName         (const std::string& port_name_         );
			void setEmailNotifiaction(const std::string& email_notification_);
			void setCameraName       (const std::string& camera_name_       );
			void setAgeTreshold      (int                age_treshold_      );
			void setFaceConfidence   (float              face_confidence_   );
			void setMinEyeDistance   (float              min_eye_distance_  );
			void setMaxEyeDistance   (float              max_eye_distance_  );
			void setMatchingTreshold (float							 matching_treshold_ );
			void setIndex            (int                index_             );




		private:
			std::string location_name_     ;
			std::string port_name_         ;
			std::string email_notification_;
			std::string camera_name_       ;
			int         age_treshold_      ;
			float       face_confidence_   ;
			float       min_eye_distance_  ;
			float       max_eye_distance_  ;
			float				matching_treshold_ ;
		  int				  index_          	 ;

			//for email notification
			std::vector<int> person_indexs_;
		};


	}
}

#endif

