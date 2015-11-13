#ifndef Bio_MainMenu_INCLUDED
#define Bio_MainMenu_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioMainMenu : public wxMenuBar
		{
		public:
			BioMainMenu();
			virtual ~BioMainMenu();

		private:
			void create();
		};		
	}
}

#endif
