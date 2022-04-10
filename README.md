# Http Server Wapper
HTTP basic functionalities, GET, POST, DELETE, PUT for now only 2 implemented.

-—HTTP Server Wrapper Explanation—-

Here it is a small QT Console project that wrap basics HTTP Server functionalities and is re-usable. The abstraction is between low level sockets and support multithreaded connections, none of the proper classes need to be re-implemented for now, except (HttpNonSecureSocket).

HttpNonSecureSocket this class fallows a pattern that can be remove or re-implemented, but Why is that ? Well this class inherit from HttpSocket and override its methods. That means that the programmer/client could make another  class to implement a new socket with SSL capabilities just subclassing HttpSocket interface/abstract class. For now a non secure socket has been used, but this can be change.

HttpNonSecureSocket Implements a HTTP Socket non secure meaning that it does not support SSL or any other secure type for now and is the core of the request system that handle every made request and call the respective obj to handle this. Every request ,must be execute it into an ClientImplementation object.

Note: HttpNonSecureSocket does not need to be modified but if more support is need then the client/programmer could easily extend the class or re-implemented through subclassing HttpSocket.

If the client/programmer decide to extend HttpSocket class with the finality to improve a socket that supports more secure capabilities or whatever the client/programmer want to do, then the new class extension/implementation must be set it, and this is done in the HttpServer.cpp file where IncommingConnection() method is located, where //creating abstract http socket with a new HttpNonSecureSocket instance
    HttpSocket *httpThreadedSocket = new HttpNonSecureSocket(descriptor, this); is. So there HttpNonSecureSocket() must be replace by the new socket re-implementation.

Note: All the classes made use of smart pointers std::shared_ptr<>() and std::unique_ptr<>() to avoid dangling pointers since not all the time Qt parent child relationship can be used.

HTTP Server Wrapper Architecture

——server———
Implement HttpServer and inherit from QTcpServer

-handle incoming connections
-create threaded client connections

——threaded socket——
Implement HttpSocket abstract or interface class and inherit from QThread

-onNewDataReady slot interface method
-onClosedConnection slot interface method

Implement HttpNonSecureSocket class and inherit from HttpSocket interface

-override methods

———http request———
Implement HttpRequest abstract class 

-httpCommand string variable
-listRoute string list variable
-getHttpCommand interface method return string
-getListRoute interface method return string list

Implement HttpRequestValidator and inherit HttpRequest class

-HttpRequestValidator(string/anything) method return HttpRequest

Implement ClientImplementation interface class 

-execute interface method

ClientImplementation class has a setter to set a HttpRequestValidator.

ClientImplementation class has a setter to set a new negotiator (QTcpSocket *) to negotiate with clients.

ClientImplementation class has a composite object of HttpRequestValidator aiming to allow the client/programmer to have access to HTTP methods and parameters.

ClientImplementation class has a composite object of JsonEngine to allow the client/programmer to have access to JSON capabilities.

HttpRequestValidator obj allows the client/programmer to access request arguments/parameters even the HTTP command.

——Server HTTP Wrapper Usage-—

Just write whatever class or code you want and give it form in the execute method in the HttpRequestHandler.cpp file, is where the core for the submitted request is handle. No need to worry about more things not even subclassing is need it. There you will have access to class member like parameters and request command.

Note: if you wonder. Yes of course a HTTP Server must accept parameters/arguments and there you have it. HttpRequestValidator class deal with it, but the use of this class is internal that means you don’t need to worry about it. ClientImplementation abstract/interface class will have access to HttpRequest class members by calling params obj then he programmer/client will be able to retrieve a list of arguments from a Request, even the submitted methods ex: GET, PUT, POST or DELETE, even better the ClientImplementation has capabilities to do some JSON operations by calling jsonEngine obj.

----ROUTING---

Basic Routing concept is possible by accessing Params object.

Params->command(“right http method”) can be GET, POST, DELETE and PUT, to verify if its the right http method.

Params->getArgs(arg number).startsWith(“right parameter”) to get the right argument after the first / in the scheme or URL.

Note: Remember to validate the argument/parameter every time trying to get arguments. Ex: if client/programmer wants to grab the 2 argument for this scheme: ( 127.0.0.1:port/search/id/ ) then the 1st argument here is “search” and 2nd is “id” so client/programmer must validate if 2nd argument exist in the scheme before consul it, and this is done by calling Params->validate(arg number), this will return true if argument exist in the scheme.

Note: Params, NegotiatorInstance and jsonEngine are composite object of ClientImplementation abstract class, is done in this way to avoid dependencies and class explosion.
 
jsonEngine is already instantiated and initialised in the ClientImplementation instantiation.

Note: HttpRequestValidator has to be set to allow the programmer/client implementation class to have access to arguments/parameters, and this is done by ClientImplementation->setHttpRequestValidator(&requestValidator); and no need to be touched

—Important— 

1- Validate argument/parameter before retrieve
2- Parameter/arguments count start at 0
3- Http method it’s only available in params->command() 

Note: Remember to set the negotiator this is for negotiate data back with client connection and can be done with ClientImplementation->setNegotiator(socketInstance);

Remember not need to worry about non of the classes already implemented, the only class and method thought to be touch is HttpRequestHandler execute method.

An example is written where JSON operations are made.

Note: Starting server required a port in this case port 6082 is used.

Example parameters to be passed to the explorer

http://127.0.0.1:6082/append/value/George/Smit/Georgia20144htAve/EastTown/merried/4260/

-----Example----

Note: this example is made with a different build code implementation then the original uploaded with the code.

1 - adding a record to a database with a front-end DB gestor application that i developed.

![image](https://user-images.githubusercontent.com/93591202/158585345-866c6ef5-5c41-4a95-859e-8ab439770a2c.png)

2 - retrieving JSON data from a backend API implemented with this Http Server Wrapper.

![image](https://user-images.githubusercontent.com/93591202/158585751-d2e1f841-a321-4f65-8545-b5b7c1fc249e.png)

3 - Hosting a web page and Serving statics files .html and .css.

![image](https://user-images.githubusercontent.com/93591202/162624755-89e1a1c8-02fc-4861-8389-88c57042f363.png)

