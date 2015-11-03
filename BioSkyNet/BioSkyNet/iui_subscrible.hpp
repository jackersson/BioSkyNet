#ifndef Bio_Properties_Utils_INCLUDED
#define Bio_Properties_Utils_INCLUDED


namespace SmartBio
{
	namespace View
	{
		class IUiSubscrible
		{
		public:
			IUiSubscrible() {}
			~IUiSubscrible() {}

			void subscribe()
			{
				do_subscribe();
			}

			void create()
			{
				do_create();
			}

			void unsubscribe()
			{
				do_unsubscribe();
			}
		private:
			virtual void do_subscribe() = 0;
			virtual void do_unsubscribe() = 0;
			virtual void do_create() = 0;

		};
	}
}

#endif


