#include "LoggerPlatform.hpp"

#include <iostream>
#include <string>


LoggerPlatform::~LoggerPlatform()
{
}


LoggerPlatform::LoggerPlatform()
{
}


SyslogLogger::SyslogLogger()
  : LoggerPlatform()
{
}


void
SyslogLogger::logMessage( const std::string& message ) const
{
  /*
   * well... this should be the syslog part.
   */
  std::cout << "SYSLOG: " << message << std::endl;
}


TerminalLogger::TerminalLogger()
  : LoggerPlatform()
{
}


void
TerminalLogger::logMessage( const std::string& message ) const
{
  std::cout << "TERMINAL: " << message << std::endl;
}

