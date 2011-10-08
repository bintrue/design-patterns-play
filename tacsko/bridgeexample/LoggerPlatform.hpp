#ifndef _LOGGER_PLATFORM_HPP_
#define _LOGGER_PLATFORM_HPP_

#include <string>

class LoggerPlatform
{
  public:
    virtual void logMessage( const std::string& message ) const = 0;
  protected:
    LoggerPlatform();
    virtual ~LoggerPlatform();
};


class SyslogLogger : public LoggerPlatform
{
  public:
    SyslogLogger();
    virtual void logMessage( const std::string& message ) const;
  /*
   * the stuff needed for syslog...
   */
};


class TerminalLogger : public LoggerPlatform
{
  public:
    TerminalLogger();
    virtual void logMessage( const std::string& message ) const;
};

#endif

