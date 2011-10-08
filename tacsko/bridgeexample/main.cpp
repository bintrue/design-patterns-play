#include <iostream>
#include <string>

#include "LoggerPlatform.hpp"
#include "Logger.hpp"

int main()
{

  SyslogLogger syslog;
  TerminalLogger termlog;

  SimpleLogger simpleLoggerUsingSyslog( syslog );
  FilteredLogger filterLoggerUsingTerminal( 2, termlog );

  Logger* logger( &simpleLoggerUsingSyslog );
  logger->logMessage( 1, "appletree level one" );
  logger->logMessage( 2, "appletree level two" );
  logger->logMessage( 3, "appletree level three" );

  std::cout << "Switching to filtered logger. " << std::endl;

  logger = &filterLoggerUsingTerminal;
  logger->logMessage( 1, "appletree level one" );
  logger->logMessage( 2, "appletree level two" );
  logger->logMessage( 3, "appletree level three" );

  return 0;
}

