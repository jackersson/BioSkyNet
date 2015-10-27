#ifndef BioControl_Resource_INCLUDED
#define BioControl_Resource_INCLUDED

namespace SmartBio
{
	namespace View
	{
		/*
		Class for information storage for UI controls.
		For example you need to create resource object with all control Name, Hint, Hotkeys.
		*/
		template <typename ItemType>
		class BioControlResource
		{

		public:
			BioControlResource() {}
			virtual ~BioControlResource() {}

			ItemType get(int index, bool& error )
			{
				ItemType item;
				error = find(index, item);
				return item;
			}		

			std::map<int, ItemType> const& childrens() const
			{
				return info_;
			}

			bool insert(int index, ItemType item)
			{
				auto elem = info_.find(index);
				if (elem != info_.end())									
					return false;
				

				info_.insert(std::pair<int, ItemType>(index, item));
				return true;
			}

		protected:
			std::map<int, ItemType> info_;
			void initialize()
			{
				do_initialize();
			}

		private:
			virtual bool find(int index, ItemType& item) const
			{
				auto elem = info_.find(index);
				if (elem != info_.end())
				{
					item = elem->second;
					return true;
				}
				return false;
			}
			virtual void do_initialize() = 0;

		};
	}
}

#endif

