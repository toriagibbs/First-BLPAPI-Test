#define NOMINMAX
#include <blpapi_defs.h>
#include <blpapi_element.h>
#include <blpapi_event.h>
#include <blpapi_eventdispatcher.h>
#include <blpapi_exception.h>
#include <blpapi_message.h>
#include <blpapi_name.h>
#include <blpapi_request.h>
#include <blpapi_session.h>
#include <blpapi_subscriptionlist.h>

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace BloombergLP;
using namespace blpapi;


class ToriaTest
{
private:
  typedef std::map<std::string, std::string> FiltersMap;

  std::string    d_host;
  int            d_port;
  Identity       d_identity;
  std::string    d_authOptions;
  SessionOptions d_sessionOptions;
  int            d_maxResults;
  Name           d_requestType;
  FiltersMap     d_filters;
  std::string    d_query;
  bool           d_partialMatch;

  void initSessionOptions()
  {
    d_sessionOptions.setServerHost(d_host.c_str());
    d_sessionOptions.setServerPort(d_port);
    d_sessionOptions.setAuthenticationOptions(d_authOptions.c_str());
  }

  bool sendRequest(Session* session)
  {
    return true;
  }
  
  void processResponse(const Event& event)
  {
  }

  void eventLoop(Session* session)
  {
  }

public:
  ToriaTest() : d_host("10.8.8.1")
	      , d_port(8194)
	      , d_maxResults(10)
	      , d_requestType("instrumentListRequest")
	      , d_query("IBM")
	      , d_partialMatch(false)
  {}

  void run()
  {
    initSessionOptions();
    Session session(d_sessionOptions);

    if (!session.start()) {
      std::cout << "*** Failed to start session!" << std::endl;
      return;
    }

    
  }

};


int main()
{
  std::cout << "Starting session" << std::endl;
  
  ToriaTest tt;
  tt.run();

  std::cout << "Done" << std::endl;
  
  return 0;
}
