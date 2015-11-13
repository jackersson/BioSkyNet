#ifndef Icon_Loadable_INCLUDED
#define Icon_Loadable_INCLUDED

namespace SmartBio
{
	namespace View
	{

		class IconLoadable
		{

		public:
			IconLoadable();

			IconLoadable( std::string icon_filename );

			virtual ~IconLoadable();

			virtual wxIcon   icon  ();
			virtual wxBitmap bitmap();

		private:
			wxBitmap loadBitmap(std::string const& filename);
			wxIcon   loadIcon  (std::string const& filename);
		private:		
			std::string icon_filename_;
		};
	}
}

#endif