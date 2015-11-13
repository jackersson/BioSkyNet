#ifndef UI_Notifications_Included
#define UI_Notifications_Included

#include "Poco/Notification.h"
#include "../BioSkyNetData/bio_person_binder.hpp"
//#include "../BioSkyNetData/bio_photo_item_binder.hpp"

namespace SmartBio
{
	namespace View
	{
		//Fires when we press Add New Person or Open Existing Profile
		class CreatePersonTabNotification : public Poco::Notification // TODO use Interface
		{
		public:
			CreatePersonTabNotification(const Data::BioPerson& data) : data_(data), default_flag_(false)
			{}

			CreatePersonTabNotification(bool default_update = true) : default_flag_(default_update)
			{}

			~CreatePersonTabNotification()
			{}

			bool isDefault() const
			{
				return default_flag_;
			}

			const Data::BioPerson& person() const
			{
				return data_;
			}

		private:
			bool default_flag_;
			Data::BioPerson data_;			
		};		
	}
}

#endif