#ifndef LWIP_HTTPD_STRUCTS_H
#define LWIP_HTTPD_STRUCTS_H

#include "httpd.h"

/** This string is passed in the HTTP header as "Server: " */
#ifndef HTTPD_SERVER_AGENT
#define HTTPD_SERVER_AGENT "lwIP/1.3.1 (http://savannah.nongnu.org/projects/lwip)"
#endif

/** Set this to 1 if you want to include code that creates HTTP headers
 * at runtime. Default is off: HTTP headers are then created statically
 * by the makefsdata tool. Static headers mean smaller code size, but
 * the (readonly) fsdata will grow a bit as every file includes the HTTP
 * header. */
 //开启之后LWIP会自动加入HTTP 200 OK 等信息，不用自己做进HTML文件中了
#ifndef LWIP_HTTPD_DYNAMIC_HEADERS
#define LWIP_HTTPD_DYNAMIC_HEADERS 0
#endif


#if LWIP_HTTPD_DYNAMIC_HEADERS
/** This struct is used for a list of HTTP header strings for various
 * filename extensions. */
typedef struct
{
  const char *extension;
  const char *content_type;
} tHTTPHeader;

/** A list of strings used in HTTP headers (see RFC 1945 HTTP/1.0 and
 * RFC 2616 HTTP/1.1 for header field definitions) */
static const char * const g_psHTTPHeaderStrings[] =
{
 "HTTP/1.0 200 OK\r\n",
 "HTTP/1.0 404 File not found\r\n",
 "HTTP/1.0 400 Bad Request\r\n",
 "HTTP/1.0 501 Not Implemented\r\n",
 "HTTP/1.1 200 OK\r\n",
 "HTTP/1.1 404 File not found\r\n",
 "HTTP/1.1 400 Bad Request\r\n",
 "HTTP/1.1 501 Not Implemented\r\n",
 "Content-Length: ",
 "Connection: Close\r\n",
 "Connection: keep-alive\r\n",
 "Server: "HTTPD_SERVER_AGENT"\r\n",
 "\r\n<html><body><h2>404: The requested file cannot be found.</h2></body></html>\r\n"
};

/* Indexes into the g_psHTTPHeaderStrings array */
#define HTTP_HDR_OK             0 /* 200 OK */
#define HTTP_HDR_NOT_FOUND      1 /* 404 File not found */
#define HTTP_HDR_BAD_REQUEST    2 /* 400 Bad request */
#define HTTP_HDR_NOT_IMPL       3 /* 501 Not Implemented */
#define HTTP_HDR_OK_11          4 /* 200 OK */
#define HTTP_HDR_NOT_FOUND_11   5 /* 404 File not found */
#define HTTP_HDR_BAD_REQUEST_11 6 /* 400 Bad request */
#define HTTP_HDR_NOT_IMPL_11    7 /* 501 Not Implemented */
#define HTTP_HDR_CONTENT_LENGTH 8 /* Content-Length: (HTTP 1.1)*/
#define HTTP_HDR_CONN_CLOSE     9 /* Connection: Close (HTTP 1.1) */
#define HTTP_HDR_CONN_KEEPALIVE 10 /* Connection: keep-alive (HTTP 1.1) */
#define HTTP_HDR_SERVER         11 /* Server: HTTPD_SERVER_AGENT */
#define DEFAULT_404_HTML        12 /* default 404 body */


#define HTTP_HDR_HTML           "Content-type: text/html\r\n\r\n"
#define HTTP_HDR_SSI            "Content-type: text/html\r\nExpires: Fri, 10 Apr 2008 14:00:00 GMT\r\nPragma: no-cache\r\n\r\n"
#define HTTP_HDR_GIF            "Content-type: image/gif\r\n\r\n"
#define HTTP_HDR_PNG            "Content-type: image/png\r\n\r\n"
#define HTTP_HDR_JPG            "Content-type: image/jpeg\r\n\r\n"
#define HTTP_HDR_BMP            "Content-type: image/bmp\r\n\r\n"
#define HTTP_HDR_ICO            "Content-type: image/x-icon\r\n\r\n"
#define HTTP_HDR_APP            "Content-type: application/octet-stream\r\n\r\n"
#define HTTP_HDR_JS             "Content-type: application/javascript\r\n\r\n"
#define HTTP_HDR_RA             "Content-type: application/javascript\r\n\r\n"
#define HTTP_HDR_CSS            "Content-type: text/css\r\n\r\n"
#define HTTP_HDR_SWF            "Content-type: application/x-shockwave-flash\r\n\r\n"
#define HTTP_HDR_XML            "Content-type: text/xml\r\n\r\n"
#define HTTP_HDR_PDF            "Content-type: application/pdf\r\n\r\n"

#define HTTP_HDR_DEFAULT_TYPE   "Content-type: text/plain\r\n\r\n"

/** A list of extension-to-HTTP header strings (see outdated RFC 1700 MEDIA TYPES
 * and http://www.iana.org/assignments/media-types for registered content types
 * and subtypes) */
static const tHTTPHeader g_psHTTPHeaders[] =
{
 { "html", HTTP_HDR_HTML},
 { "htm",  HTTP_HDR_HTML},
 { "shtml",HTTP_HDR_SSI},
 { "shtm", HTTP_HDR_SSI},
 { "ssi",  HTTP_HDR_SSI},
 { "gif",  HTTP_HDR_GIF},
 { "png",  HTTP_HDR_PNG},
 { "jpg",  HTTP_HDR_JPG},
 { "bmp",  HTTP_HDR_BMP},
 { "ico",  HTTP_HDR_ICO},
 { "class",HTTP_HDR_APP},
 { "cls",  HTTP_HDR_APP},
 { "js",   HTTP_HDR_JS},
 { "ram",  HTTP_HDR_RA},
 { "css",  HTTP_HDR_CSS},
 { "swf",  HTTP_HDR_SWF},
 { "xml",  HTTP_HDR_XML},
 { "xsl",  HTTP_HDR_XML},
 { "pdf",  HTTP_HDR_PDF}
};

#define NUM_HTTP_HEADERS (sizeof(g_psHTTPHeaders) / sizeof(tHTTPHeader))

#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */

#if LWIP_HTTPD_SSI
static const char * const g_pcSSIExtensions[] = {
  ".shtml", ".shtm", ".ssi", ".xml"
};
#define NUM_SHTML_EXTENSIONS (sizeof(g_pcSSIExtensions) / sizeof(const char *))
#endif /* LWIP_HTTPD_SSI */

#endif /* LWIP_HTTPD_STRUCTS_H */
