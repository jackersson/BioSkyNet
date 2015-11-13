#include "stdafx.h"
#include "bio_location.hpp"

#include "Poco/StringTokenizer.h"

namespace SmartBio
{
	namespace Data
	{
		BioLocation::BioLocation() : location_name_     	("")
			                         , port_name_         	("")
			                         , email_notification_	("")
			                         , camera_name_       	("")
			                         , age_treshold_      	(0)
			                         , face_confidence_   	(0)
			                         , min_eye_distance_  	(0)
															 , max_eye_distance_  	(0)
															 , matching_treshold_ 	(0)
		{

		}
		BioLocation::BioLocation(  int index
			                       , const std::string& location_name
			                       , const std::string& port_name
			                       , const std::string& email_notification
			                       , const std::string& camera_name
			                       , int                age_treshold
			                       , float              face_confidence
			                       , float              min_eye_distance
			                       , float							 max_eye_distance
			                       , float							 matching_treshold  ) 
			                       : index_(index)
			                       , location_name_     (location_name       )
			                       , port_name_         (port_name						)
			                       , email_notification_(email_notification	)
			                       , camera_name_       (camera_name 				)
			                       , age_treshold_      (age_treshold				)
			                       , face_confidence_   (face_confidence			)
			                       , min_eye_distance_  (min_eye_distance		)
			                       ,	max_eye_distance_  (max_eye_distance		)
			                       ,	matching_treshold_ (matching_treshold  	)


		{

		}

		BioLocation::~BioLocation() {}


		int BioLocation::index() const
		{
			return index_;
		}

		const std::string& BioLocation::location_name() const
		{
			return location_name_;
		}

		const std::string& BioLocation::port_name() const
		{
			return port_name_;
		}

		const std::string& BioLocation::email_notification() const
		{
			return email_notification_;
		}

		const std::string& BioLocation::camera_name() const
		{
			return camera_name_;
		}

		int BioLocation::age_treshold() const
		{
			return age_treshold_;
		}

		float BioLocation::face_confidence() const
		{
			return face_confidence_;
		}

		float BioLocation::min_eye_distance() const
		{
			return min_eye_distance_;
		}

		float BioLocation::max_eye_distance() const
		{
			return max_eye_distance_;
		}

		float BioLocation::matching_treshold() const
		{
			return matching_treshold_;
		}		

		void BioLocation::setIndex(int index)
		{
			index_ = index;
		}

		void BioLocation::setLocationName(const std::string& location_name)
		{
			location_name_ = location_name;
		}

		void BioLocation::setPortName(const std::string& port_name)
		{
			port_name_ = port_name;
		}

		void BioLocation::setEmailNotifiaction(const std::string& email_notification)
		{
			email_notification_ = email_notification;

			person_indexs_.clear();
			if (email_notification_.empty())
				return;


			Poco::StringTokenizer tk(email_notification_, ",", Poco::StringTokenizer::TOK_TRIM);

			for (Poco::StringTokenizer::Iterator it = tk.begin(); it != tk.end(); ++it)
			{
				std::string temp(*it);
				person_indexs_.push_back(stoi(temp));
			}
		}

		void BioLocation::setCameraName(const std::string& camera_name)
		{
			camera_name_ = camera_name;
		}

		void BioLocation::setAgeTreshold(int age_treshold)
		{
			age_treshold_ = age_treshold;
		}

		void BioLocation::setFaceConfidence(float face_confidence)
		{
			face_confidence_ = face_confidence;
		}

		void BioLocation::setMinEyeDistance(float min_eye_distance)
		{
			min_eye_distance_ = min_eye_distance;
		}

		void BioLocation::setMaxEyeDistance(float max_eye_distance)
		{
			max_eye_distance_ = max_eye_distance;
		}

		void BioLocation::setMatchingTreshold(float matching_treshold)
		{
			matching_treshold_ = matching_treshold;
		}

		const std::vector<int>&   BioLocation::personIndexs()   const
		{
			return person_indexs_;
		}

	}
}