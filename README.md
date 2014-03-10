FIXmessages
===========

The FIX protocol stands for Financial Information eXchange, and it describes a communication standard for real-time exchange of information associated with the securities transactions and markets.

This project details the implementation of a FIX message class. The objects of the class are initialized with a string representing a well-formed FIX message. The class automatically parses the message and creates an associative map of the string's content.

The map will allow the user to retrieve information in the map simply by providing the appropriate tag.
