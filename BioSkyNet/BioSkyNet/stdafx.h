#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/aui/auibook.h>
#include <wx/aui/aui.h>
#include <wx/aui/tabmdi.h>
#include <wx/propgrid/manager.h>
#include <wx/listbook.h>
#include <wx/aboutdlg.h>
#include <wx/artprov.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/spinctrl.h>
#include <wx/gbsizer.h>
#include <wx/infobar.h>
#include <wx/propgrid/advprops.h>
#include <wx/dataview.h>
#include <wx/commandlinkbutton.h>
#include <wx/datetime.h>
#include <wx/variant.h>

#include <Poco/NObserver.h>
#include <Poco/NotificationCenter.h>

#include "Poco/Data/Date.h"
#include "Poco/Data/Time.h"
#include "Poco/Data/LOB.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/RecordSet.h"
#include "Poco/Data/SQLChannel.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/SQLite/Utility.h"
#include "Poco/Data/SQLite/Notifier.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/Data/TypeHandler.h"
#include "Poco/Nullable.h"
#include "Poco/Data/Transaction.h"
#include "Poco/Data/DataException.h"
#include "Poco/Data/SQLite/SQLiteException.h"
#include "Poco/Tuple.h"
#include "Poco/Any.h"
#include "Poco/SharedPtr.h"
#include "Poco/DynamicAny.h"
#include "Poco/DateTime.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/Thread.h"
#include "Poco/AutoPtr.h"
#include "Poco/Exception.h"
#include "Poco/RefCountedObject.h"
#include "Poco/Stopwatch.h"
#include "Poco/Delegate.h"


#include "../SmartInterfaces/patterns.hpp"
//#include "../SmartBioModel/notifications.hpp"


#include <map>