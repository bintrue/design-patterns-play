#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include "LoggerPlatform.hpp"

#include <string>

class Logger
{
  public:
    Logger( LoggerPlatform& loggerPlatform );
    virtual void logMessage( int logLevel,  const std::string& message ) const = 0;

  protected:
    void log( const std::string& message ) const;

  private:
    LoggerPlatform& m_loggerPlatform;
};


class SimpleLogger : public Logger
{
  public:
    SimpleLogger( LoggerPlatform& loggerPlatform );
    virtual void logMessage( int logLevel,  const std::string& message ) const;
};


class FilteredLogger : public Logger
{
  public:
    FilteredLogger( int filterLevel,  LoggerPlatform& loggerPlatform );
    virtual void logMessage( int logLevel,  const std::string& message ) const;

  private:
    int m_filterLevel;
};

#endif

