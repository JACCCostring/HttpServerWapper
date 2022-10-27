# Http Server Wapper

-—HTTP Server Wrapper Explanation—-

Here HTTP wrapper with basics HTTP Server functionalities HTTP basic functionalities are, GET, POST, DELETE, PUT.

Yes, i know threre are many Http thrird party libraries out there but i wanted to test what is it too implement a protocol and what it takes for, also how everything works in the backbone.

HttpNonSecureSocket this class fallows a pattern that can be remove or re-implemented, but Why is that ? Well this class inherit from HttpSocket and override its methods. That means that the programmer/client could make another class to implement for example a new socket with SSL capabilities just subclassing HttpSocket interface/abstract class. For now a non secure socket has been used, but this can be change.

<b>Note:</b> HttpNonSecureSocket does not need to be modified but if more support is need then the client/programmer could easily extend the class or re-implemented through subclassing HttpSocket.

<b>Note:</b> All the classes made use of smart pointers std::shared_ptr<>() and std::unique_ptr<>() to avoid dangling pointers since not all the time Qt parent child relationship is being used here.

<b>HTTP Server Wrapper Architecture</b>

——Server———
Implement HttpServer and inherit from QTcpServer

-handle incoming connections
-create threaded client connections 

<b>Note:</b> I know the best way to do it. It's moving to a thread an used defined object that inherit QObject, but on later project versions, it might be a good thing to implement.

——threaded socket——
Implement HttpSocket abstract or interface class and inherit from QThread

-onNewDataReady slot interface method
-onClosedConnection slot interface method

Implement/define HttpNonSecureSocket class and inherit from HttpSocket interface

<b>--How request are handled ?--</b>

all incoming request are handled with a HttpRequestValidator class that parsed all recieved data.

ClientImplementation class has a method to set an HttpRequestValidator.

ClientImplementation class has a method to set a negotiator (QTcpSocket *) to send back and forward data to valid connections connected to the server.

And all that is setted in HttpNonSecureSocket class implementation in onNewDataReady() overrided method.

ClientImplementation class has a composite object of HttpRequestValidator aiming to allow the client/programmer to perform HTTP methods like POST, GET, etc and read parameters.

ClientImplementation class has a composite object of JsonEngine to allow the client/programmer to perform JSON actions.

<b>Note:</b> If you wonder. Yes of course an HTTP Server must accept parameters/arguments and XML or JSON data and there you have it. HttpRequestValidator class deal with it, but the use of this class is internal that means you don’t need to touch it or worry about it. ClientImplementation abstract/interface class will have access to HttpRequest class members by calling params object then the client/programmer will be able to retrieve a list of arguments from a Request, even the submitted methods ex: GET, PUT, POST or DELETE.

And the ClientImplementation as an instancieted object for JSON capabilities to do some JSON operations by calling <b>jsonEngine</b> object.

But for now parameters supports are JSON format but not Query parameters yet. I might work on it on later project versions.

——Server HTTP Wrapper Usage-—

This repository here it's pushed with an usage scenario example. But going strait to the point for finl use then, 

----ROUTING---

Basic Routing concept is possible by accessing Params object.

Example:

<b>if(params->getRequest()["Method"].startsWith("GET"))
   if(params->getRequest()["Route"].startsWith("/coords"))
   doSomething(coords);</b>

-—Client/Developer Usage—-

Going strait to the poin.

<b>Note:</b> Not class here need to be touched for usage, but if you want to implement as developer then, not need to do this step.

<b>1:</b> Make a static library from Qt Creator, i wont explain here how to do that. But clone this repo, then make it an static library

<b>2:</b> Add it as an static library to your project, then good to go.

An example is written where JSON operations and serving static files like HTML and CSS is shown below. <b>Note:</b> JavaScript is also possible

-----Example----

1 - adding a record to a database with a front-end DB gestor application that i developed earlier.

![image](https://user-images.githubusercontent.com/93591202/158585345-866c6ef5-5c41-4a95-859e-8ab439770a2c.png)

2 - retrieving JSON data from a an API implemented with this Http Wrapper Server.

![image](https://user-images.githubusercontent.com/93591202/158585751-d2e1f841-a321-4f65-8545-b5b7c1fc249e.png)

3 - Hosting a web page and Serving statics files .html and .css.

![image](https://user-images.githubusercontent.com/93591202/162624755-89e1a1c8-02fc-4861-8389-88c57042f363.png)

