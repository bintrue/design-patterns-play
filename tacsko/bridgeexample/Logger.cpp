#include "Logger.hpp"
#include "LoggerPlatform.hpp"

#include <string>
#include <sstream>
#include <iostream>

Logger::Logger( LoggerPlatform& loggerPlatform )
  : m_loggerPlatform( loggerPlatform )
{
}


void
Logger::log( const std::string& message ) const
{
  m_loggerPlatform.logMessage( message );
}


SimpleLogger::SimpleLogger( LoggerPlatform& loggerPlatform )
  : Logger( loggerPlatform )
{
}


void
SimpleLogger::logMessage( int logLevel,  const std::string& message ) const
{
  std::stringstream messageStream;
  messageStream << logLevel << " - " << message;
  log( messageStream.str()  );
}


FilteredLogger::FilteredLogger( int filterLevel, LoggerPlatform& loggerPlatform )
  : Logger( loggerPlatform )
  , m_filterLevel( filterLevel )
{
}


void
FilteredLogger::logMessage( int logLevel,  const std::string& message ) const
{
  if ( logLevel > m_filterLevel )
  {
    std::cout << "log message filtered: " << message << std::endl;
    return;
  }

  std::stringstream messageStream;
  messageStream << logLevel << " -> " << message;
  log( messageStream.str()  );
}

