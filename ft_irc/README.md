
# IRC Server Architecture Documentation
Related to 42 ft_irc Subject version 8.2

## Table of Contents
1. [Message Management System (IrcMM)](#message-management-system)
2. [Validation Classes](#validation-classes)
   - [ChanName](#channame-class)
   - [HostName](#hostname-class)
   - [UserName](#username-class)
   - [NickName](#nickname-class)
3. [Core Components](#core-components)
   - [Parser](#parser-class)
   - [Client](#client-class)
   - [Channel](#channel-class)
   - [Server](#server-class)
4. [Command Implementation Logic](#command-implementation-logic)

---

## Message Management System (IrcMM)

### Overview

The `IrcMM` (IRC Message Manager) class is a comprehensive message formatting system designed for IRC server implementations. It serves as a centralized repository for composing and managing all IRC protocol messages, including both server replies and error messages. The class encapsulates the complex formatting requirements of the IRC protocol, providing a clean interface for generating standardized messages throughout the server codebase.

### Architecture and Design

The class follows a well-structured design pattern with clear separation between public interface and private implementation. It maintains an internal map (`messages_`) that stores message templates indexed by their numeric codes, following the standard IRC numeric reply system. The constructor initializes this map through a dedicated `initializeMessages()` method, ensuring all message templates are available upon instantiation. The class also provides standard copy constructor, assignment operator, and destructor, making it a proper C++ class that can be safely copied and assigned.

### Message Types and Coverage

The `IrcMM` class provides extensive coverage of IRC protocol messages, spanning from initial connection messages (like `RPL_WELCOME` and `RPL_YOURHOST`) to complex operational responses. It handles welcome messages (001-005), trace and statistics messages (200-263), user information queries (301-395), channel operations (321-395), and a comprehensive set of error messages (401-502). Additionally, it includes custom extensions for common IRC actions like `PRIVMSG`, `KICK`, and `PART`, which are assigned non-standard numeric codes (600-602) for internal use.

### Formatting Capabilities

Each message type has a corresponding `Fmt_` method that accepts the necessary parameters to construct a properly formatted IRC message. These methods handle the insertion of dynamic data such as nicknames, usernames, hostnames, channel names, and timestamps into standardized message templates. The class uses custom types (`NickName`, `HostName`, `UserName`, `ChanName`) for parameter validation and type safety. Two key utility methods, `getFmtMsg()` and `getFmtMsg_no_prefix()`, provide flexible message formatting using tag substitution, allowing for template-based message generation with placeholder replacement.

### Practical Applications

This centralized approach to message management offers several advantages for IRC server development. It ensures consistency in message formatting across the entire codebase, reduces code duplication, and makes it easier to maintain compliance with IRC protocol specifications. The class acts as a single source of truth for all server messages, making updates and modifications simpler. By providing both direct formatting methods and template-based substitution, it accommodates different usage patterns throughout the server implementation, from simple static messages to complex dynamic responses requiring multiple parameter substitutions.

---

## Validation Classes

### ChanName Class

#### Overview

The `ChanName` class is a specialized validation and encapsulation wrapper for IRC channel names. It ensures that all channel names used throughout the IRC server implementation strictly conform to the IRC protocol specifications. By enforcing validation rules at the point of construction, the class prevents invalid channel names from propagating through the system, providing a type-safe guarantee that any `ChanName` object contains a valid, protocol-compliant channel identifier.

#### Validation Framework

The class implements a comprehensive three-tier validation system through private static methods. The `validatePrefix()` method ensures that channel names begin with one of the four valid IRC channel prefixes: '#' (standard channels), '&' (local channels), '!' (safe channels), or '+' (modeless channels). The `validateCharacters()` method prohibits control characters and special symbols that are forbidden in the IRC protocol, including NUL (0x00), BELL (0x07), carriage return (0x0D), line feed (0x0A), space, comma, and colon characters. The `validateLength()` method enforces the constraint that channel names must be between 1 and 50 characters long. These validation methods throw specific custom exceptions (`InvalidPrefixException`, `InvalidCharacterException`, `InvalidLengthException`) that provide clear, descriptive error messages when validation fails.

#### Construction Flexibility

The `ChanName` class offers remarkable flexibility through five different constructor overloads, accommodating various channel name composition scenarios. The simplest constructor accepts a complete channel name string and validates it. A two-parameter constructor takes a prefix character and a channel string, assembling them into a complete name. A three-parameter version allows for constructing compound channel names with a prefix and two string components separated by a colon. Another variant accepts a channel ID and two string components for more complex channel naming schemes. This variety of constructors enables the class to handle different channel name formats while maintaining consistent validation across all construction paths.

#### Normalization and Storage

A critical feature of the `ChanName` class is its automatic case normalization through the `toLower()` utility function. This function converts all channel names to lowercase using a manual character-by-character transformation, ensuring case-insensitive channel name handling as required by the IRC protocol. The implementation avoids dependency on locale-specific standard library functions, providing consistent behavior across different system configurations. The normalized name is stored in the private `_channame` member variable, which is only accessible through the `get()` method for full name retrieval or the `getprefix()` method for accessing just the channel type prefix.

#### Design Patterns and Best Practices

The class follows proper C++ resource management principles with a complete set of canonical form methods including copy constructor, assignment operator, and destructor. The validation logic is centralized and consistently applied across all constructors through the private `validate()` method, ensuring that no matter how a `ChanName` object is constructed, it always contains a valid channel name. The use of custom exception classes with descriptive error messages provides excellent debugging support and clear feedback when invalid channel names are encountered. By storing the normalized channel name as an immutable value (accessible only through const getter methods), the class guarantees that once a valid `ChanName` is created, it remains valid throughout its lifetime, making it a reliable type for use throughout the IRC server codebase.

---

### HostName Class

#### Overview

The `HostName` class provides robust validation and encapsulation for IRC server hostnames and IP addresses. It serves as a type-safe wrapper that ensures all hostname values conform to valid formats, accepting traditional domain names, IPv4 addresses, and IPv6 addresses. By enforcing validation at construction time and providing a comprehensive set of comparison operators, the class enables reliable hostname handling throughout the IRC server implementation while maintaining strict protocol compliance.

#### Multi-Format Validation System

The class implements a sophisticated validation framework that recognizes three distinct hostname formats through private helper methods. The `isHostname()` method validates traditional domain names by breaking them into dot-separated segments and verifying each segment as a valid shortname (alphanumeric characters with hyphens, starting with an alphanumeric character). The `isIp4addr()` method validates IPv4 addresses by parsing four dot-separated octets, ensuring each segment contains only digits and represents a value between 0 and 255. The `isIp6addr()` method provides simplified IPv6 validation, checking for eight colon-separated hexadecimal segments of up to four characters each. All formats are subject to a maximum length constraint of 63 characters, and the central `validate()` method attempts to match the input against any of these three formats, accepting the hostname if it conforms to at least one pattern.

#### Construction and Lifecycle Management

The `HostName` class follows proper C++ canonical form with well-defined construction, copying, and destruction semantics. The default constructor initializes the hostname to "localhost", providing a sensible default value for server operations. The primary constructor accepts a string parameter and validates it before storage, throwing a `std::invalid_argument` exception if the format is invalid. Copy construction and assignment operators enable safe copying of `HostName` objects while maintaining validation guarantees. Notably, the class integrates with a logging system, recording creation and destruction events for debugging and monitoring purposes, which aids in tracking hostname lifecycle throughout the server's operation.

#### Comparison and Ordering Capabilities

Beyond basic validation and storage, the `HostName` class provides a complete suite of comparison operators (==, !=, <, >, <=, >=) that enable hostname objects to be used in sorted containers and comparison operations. These operators perform lexicographic string comparison on the underlying hostname values, allowing `HostName` objects to be stored in standard containers like `std::map` or `std::set`. This feature is particularly valuable for implementing data structures that require hostname-based indexing or sorting, such as connection tables, ban lists, or server routing information.

#### Design Philosophy and Type Safety

The class exemplifies the principle of making invalid states unrepresentable through its type system. By using the `explicit` keyword on the main constructor, it prevents implicit conversions from strings to `HostName` objects, forcing developers to consciously create validated hostname instances. The private storage of the hostname string with access only through a const getter method ensures immutability after construction. The comprehensive validation logic, while not exhaustive for all edge cases (particularly for IPv6), provides practical protection against malformed hostnames entering the system. The integration with a custom `HostNameException` class and the Logger singleton demonstrates thoughtful error handling and observability, making the class both safe and debuggable in production environments.

---

### UserName Class

#### Overview

The `UserName` class enforces strict validation rules for IRC usernames, ensuring compliance with protocol specifications and system security requirements. It acts as a protective wrapper that prevents invalid or potentially problematic usernames from being used within the IRC server. Through a comprehensive four-stage validation process executed at construction time, the class guarantees that any `UserName` object contains a properly formatted, safe username that adheres to both IRC protocol standards and system-level security constraints.

#### Four-Tier Validation Architecture

The class implements a rigorous validation system through four private helper methods that check distinct aspects of username validity. The `isReserved()` method blocks system-reserved names like "root", "bin", "daemon", "sys", and "apache" to prevent impersonation of system accounts and potential security issues. The `isValidLength()` method enforces that usernames contain between 1 and 12 characters, striking a balance between usability and protocol constraints. The `hasValidCharacters()` method implements IRC protocol requirements by prohibiting control characters including NUL (0x00), line feed (0x0A), carriage return (0x0D), spaces, and the '@' symbol, which has special meaning in IRC host masks. Finally, the `startsWithLetter()` method ensures usernames begin with an alphabetic character (a-z or A-Z), following common Unix username conventions and improving readability.

#### Exception-Based Error Reporting

Unlike the other validation classes in this IRC server codebase, `UserName` provides exceptionally detailed error reporting through its custom `UserNameException` class. Each validation failure throws a specific exception with a descriptive message indicating exactly what rule was violated and which username failed validation. For example, attempting to create a username with invalid characters produces a message like "Invalid characters in UserName >bad@name<", with the problematic username clearly marked. This granular feedback is invaluable during development and debugging, immediately identifying why a username was rejected and helping developers or administrators understand validation failures in log files.

#### Canonical Form and Lifecycle Integration

The class adheres to C++ canonical form principles with properly implemented copy constructor, assignment operator, and destructor. Similar to the `HostName` class, `UserName` integrates with a logging system to track object lifecycle events, recording creation, copying, assignment, and destruction operations. This logging integration provides audit trails for username object management throughout the server's operation. The class provides both a parameterized constructor for validation-based creation and declares (but doesn't show implementation for) a default constructor and setter method in the header, suggesting flexibility in object initialization patterns, though the primary usage pattern enforces validation at construction time.

#### Protocol Compliance and Security Focus

The validation logic directly implements IRC protocol specifications, particularly the character restrictions defined in RFC 2812 which prohibit specific octets in usernames. The comment in the implementation explicitly references the protocol's BNF notation: "any octet except NUL, CR, LF, ' ' and '@'", demonstrating careful attention to protocol compliance. The reserved name check adds an additional security layer beyond protocol requirements, preventing potential privilege escalation or confusion attacks where IRC users might attempt to masquerade as system accounts. While the header declares comparison operators (==, !=, <, >, <=, >=), their implementation isn't shown in the provided source, but their presence indicates the class is designed to work with sorted containers and enable username-based ordering, similar to the `HostName` class pattern. The combination of protocol compliance and security-conscious validation makes `UserName` a critical defensive component in the IRC server's input validation layer.

---

### NickName Class

#### Overview

The `NickName` class implements IRC nickname validation with sophisticated character normalization semantics specific to the IRC protocol. Unlike the other validation classes in this codebase, `NickName` goes beyond simple validation to implement IRC's unique case-insensitivity rules, where certain special characters are considered equivalent for comparison purposes. This dual responsibility—validating nickname format and providing protocol-compliant comparison operations—makes it a critical component for managing user identities within the IRC server, ensuring that nicknames like "User[1]" and "User{1}" are correctly recognized as equivalent according to IRC specifications.

#### IRC-Specific Character Validation

The class implements strict character restrictions through the `isValidCharacter()` helper method, which applies different rules depending on character position. The first character must be either a letter (a-z, A-Z) or one of the special IRC characters in the ranges '[' to '`' or '{' to '}'. Subsequent characters may additionally include digits (0-9) and the hyphen character ('-'). The `validate()` method enforces a maximum length of 12 characters, consistent with traditional IRC implementations. These rules align with RFC 2812 nickname specifications, ensuring that created nicknames can be properly transmitted and recognized across IRC networks. The validation includes debug output when length violations occur, indicating attention to troubleshooting during development.

#### Character Normalization Framework

The most distinctive feature of the `NickName` class is its character normalization system, implemented through two nested functor structs: `NormalizedCharEqual` and `NormalizedCharLess`. These functors perform character-level normalization where certain ASCII characters are mapped to their equivalents: '{' maps to '[', '}' to ']', '|' to '\\', and '^' to '~'. This normalization implements IRC's case-insensitivity convention for special characters, treating uppercase and lowercase bracket variants as identical. The functors are then used with standard library algorithms (`std::equal` and `std::lexicographical_compare`) in the comparison operators, enabling protocol-compliant nickname comparison without modifying the stored nickname string. This design elegantly separates storage (preserving the original form) from comparison semantics (applying IRC normalization rules).

#### Comprehensive Comparison Semantics

The class provides a complete set of six comparison operators (==, !=, <, >, <=, >=) that leverage the normalization functors to implement IRC-compliant comparisons. The equality operator uses `std::equal` with `NormalizedCharEqual` to perform character-by-character comparison with normalization, so "User[test]" equals "User{test}". The less-than operator employs `std::lexicographical_compare` with `NormalizedCharLess` to enable sorted ordering of nicknames, allowing `NickName` objects to be used as keys in `std::map` or elements in `std::set` containers. The remaining comparison operators are implemented in terms of these two fundamental operations, following the principle of defining minimal operators and deriving the rest. This comprehensive comparison support makes `NickName` suitable for any data structure requiring ordering or uniqueness testing.

#### Design Patterns and Lifecycle Management

The class follows canonical C++ form with explicit control over construction, copying, and destruction. The default constructor initializes to "Undefined" rather than an empty string, providing a distinguishable default state. The primary constructor is marked `explicit` to prevent accidental implicit conversions from strings, forcing intentional nickname creation. Logger integration tracks object lifecycle events, providing observability for debugging and auditing. The use of nested functors as comparison policy objects demonstrates sophisticated C++ design, encapsulating normalization logic in reusable components that can work with standard algorithms. The separation of validation (structural correctness) from normalization (semantic equivalence) creates a clean architecture where the stored nickname remains in its original form while comparison operations apply IRC-specific semantics transparently.

---

## Core Components

### Parser Class

#### Overview

The `Parser` class serves as the central command dispatcher for the IRC server, responsible for interpreting incoming client messages and routing them to appropriate handler methods. It acts as the bridge between raw text input from clients and the execution of IRC protocol commands, implementing a comprehensive parsing pipeline that tokenizes input, identifies commands, and delegates execution to specialized handler methods. By maintaining a reference to the server instance, the parser can coordinate actions across the entire server infrastructure while processing client requests.

#### Token Processing and Command Identification

The parsing pipeline begins with the `parse()` method, which accepts a client pointer and a raw text line. The input undergoes preprocessing through the `_trim()` helper, which strips whitespace, carriage returns, line feeds, and tabs from both ends—essential for handling the varied line-ending conventions of IRC clients. The `_split_tokens()` method then breaks the cleaned input into whitespace-separated tokens stored in the `_tokens` vector, extracting and uppercasing the first token to populate `_command` for efficient dispatch. An additional preprocessing capability exists through `_processTokens()`, which splits comma-separated values within tokens (like "JOIN #foo,#bar") into individual tokens, handling IRC's compact syntax for multi-target commands. Helper methods like `_splitString()` provide the underlying string manipulation utilities for these operations.

#### Command Dispatch Architecture

The heart of the parser is the `_backbone()` method, which implements a large if-else chain comparing the identified command against 40+ static token strings declared as class members. These tokens represent the full spectrum of IRC commands from basic connection management (PASS, NICK, USER) through channel operations (JOIN, PART, MODE, TOPIC, KICK) to information queries (WHO, WHOIS, LIST, NAMES) and administrative functions (OPER, KILL, REHASH, DIE). Each recognized command triggers a corresponding private handler method (like `_cmd_join()`, `_cmd_privmsg()`, `_cmd_mode()`) that receives the client pointer and can access the tokenized input through the parser's state. When an unrecognized command is encountered, the parser uses the static `IrcMM` message manager instance (`_mm`) to format an `ERR_UNKNOWNCOMMAND` error, logs it, stores the error code, and enqueues the response to the client.

#### Specialized Command Handlers

Several command handlers demonstrate domain-specific processing by delegating to more specialized methods. The `_cmd_mode()` handler branches into `_cmd_mode_user()` and `_cmd_mode_channel()` depending on whether the target is a user or channel, passing validated `NickName` or `ChanName` objects respectively. Similarly, `_cmd_privmsg()` splits into `_cmd_privmsg_user()` and `_cmd_privmsg_channel()` variants. This layered approach allows type-safe handling of different command contexts while sharing common parsing logic. The extensive list of handler method declarations (all private) indicates that each IRC command receives custom implementation logic appropriate to its specific requirements, from simple acknowledgments to complex multi-step operations involving channel membership, permissions, and state management.

#### Design Constraints and State Management

The parser's design reflects careful consideration of C++98 constraints and object lifecycle management. The class maintains a non-reassignable reference to the server instance (`Server& _server`), which is initialized in the constructor and cannot be changed—a design choice that necessitates disabling the copy constructor and assignment operator (declared but not defined) to prevent reference rebinding issues. The class maintains parsing state through member variables (`_tokens`, `_txt_line`, `_command`, `_error`) that are cleared and repopulated on each `parse()` call, making the parser reusable across multiple client messages. Static members include both the command token strings (shared across all parser instances for memory efficiency) and the `IrcMM` message manager (providing centralized message formatting). Logger integration tracks parser lifecycle events, while the commented-out canonical form implementations document why these methods cannot be safely implemented given the reference member constraint—demonstrating thoughtful attention to C++ semantics and potential misuse scenarios.

---

### Client Class

#### Overview

The `Client` class represents an individual IRC client connection within the server, encapsulating all state information necessary to manage a user's session. It serves as the primary data structure for tracking client identity, authentication status, connection details, and message buffers. By integrating the validated type classes (`NickName`, `UserName`, `HostName`) and managing a file descriptor through RAII principles, the class provides a robust foundation for client lifecycle management from initial connection through authentication and active participation in the IRC network.

#### State Management and Authentication Tracking

The class implements a multi-stage authentication model through carefully tracked boolean flags. The `_passAccepted` flag indicates whether the client has successfully provided the server password via the PASS command, while `_registered` tracks full registration completion (requiring PASS, NICK, and USER commands). Additional flags `_hasNick` and `_hasUser` independently track whether these specific credentials have been set, allowing the server to enforce proper registration sequencing. This granular state tracking enables the server to reject premature commands and guide clients through the proper connection handshake. The separation between "has credential" flags and "is registered" status reflects IRC's requirement that all three authentication elements must be present before granting full access to server features.

#### Identity Management Through Validated Types

Client identity is managed through instances of the validated type classes rather than raw strings. The `_nick` member is a `NickName` object, `_user` is a `UserName`, and `_host` is a `HostName`, ensuring that once set, these critical identifiers are guaranteed to be protocol-compliant. The setter methods (`setNick()`, `setUser()`, `setHost()`) construct these validated objects from strings, throwing exceptions if validation fails—preventing invalid identities from entering the system. Dual accessor patterns provide both string representations (via `getNick()`, `getUser()`, `getHost()`) and direct object references (via `getNickObj()`, `getUserObj()`, `getHostObj()`), supporting different usage scenarios. The object accessors are particularly valuable when interfacing with the `IrcMM` message manager, which can work directly with typed objects rather than requiring string conversions.

#### Buffer Management and Message Queueing

The client maintains separate input and output buffers (`_inbuf` and `_outbuf`) for asynchronous I/O operations. The input buffer accumulates incoming data from the network until complete lines can be extracted for parsing, while the output buffer queues messages awaiting transmission. The `enqueueIrcMessage()` method provides a convenient interface for adding properly formatted IRC messages to the output buffer, automatically appending the required CRLF (carriage return, line feed) line terminator mandated by the IRC protocol. This buffering strategy enables non-blocking socket operations where the server can read partial data, process complete commands as they arrive, and write responses incrementally as the socket becomes writable, preventing blocking on slow network conditions.

#### Resource Management and Copy Semantics

The class demonstrates sophisticated resource management through its use of a `FileDescriptor` RAII wrapper for the client's socket. The constructor accepts an integer file descriptor which is immediately wrapped in the `_fd` member, ensuring automatic cleanup when the client object is destroyed. Notably, the copy constructor deliberately sets `_fd` to -1 and emits a warning, recognizing that file descriptors should not be duplicated—copying client state makes sense in some contexts, but sharing or duplicating the underlying socket does not. The assignment operator similarly refuses to copy the file descriptor. Default initialization values provide sensible fallbacks: `_nick` defaults to "defa_nick" (9 characters), `_user` to "def_user" (8 characters), and `_realName` to "Unknown", ensuring the client always has identifiable values even before explicit configuration. Additional member variables (`_umode` for user modes, `_realName` for the full name field) support extended IRC functionality beyond basic authentication, with corresponding getter and setter methods providing controlled access to these attributes.

---

### Channel Class

#### Overview

The `Channel` class represents an IRC channel within the server, encapsulating all state related to a chat room including its members, operators, access control settings, and topic information. It serves as the central data structure for managing multi-user conversations, enforcing channel modes, and coordinating message distribution among participants. By maintaining separate collections for regular members, administrators (operators), and invited users, the class provides the foundation for implementing IRC's hierarchical permission system and access control mechanisms.

#### Mode Management and Access Control

The channel implements IRC's standard mode flags through a set of boolean and string member variables. The `m_invite_only` flag restricts joining to invited users, while `m_topic_restrict` controls whether only operators can modify the topic. Key-based protection is managed through `m_key_required` and `m_key` members, implementing the +k mode that requires a password for entry. User limits are enforced via `m_limit` (maximum occupancy) paired with `m_size` (current member count). The `getModes()` method constructs a mode string representation (like "+itk password") with an optional boolean parameter to control whether sensitive information like the actual key is included—useful for showing modes to channel members versus external queries. Setter methods provide both setting and unsetting capabilities (e.g., `SetInvitOnly()`/`UnsetInvitOnly()`), enabling dynamic mode changes during channel operation.

#### Member Management and Role Hierarchy

The class maintains three distinct client collections through `std::vector<Client*>`: `m_members` for all channel participants, `m_admins` for operators (distinguished by '@' prefix in IRC), and `m_invited` for users granted invite-only channel access. The `AddMember()` method implements automatic operator promotion—when the first user joins an empty channel, they're automatically added as an administrator, following IRC's convention that channel creators become initial operators. The `RemoveMember()` method includes sophisticated fallback logic: if the last operator leaves a non-empty channel, it automatically promotes the first remaining member to operator and broadcasts the mode change to all participants. Duplicate prevention is implemented through nickname comparison during additions, ensuring each client appears only once in relevant collections. Query methods (`isMember()`, `isAdmin()`, `isInvited()`) enable permission checking, while getter methods return entire collections for iteration by command handlers.

#### Message Broadcasting Infrastructure

Two broadcasting methods support different message distribution patterns. The `broadcastMessage()` method sends an IRC message to all channel members except an optional excluded client (typically the message sender, following IRC's convention that users don't receive echoes of their own actions). The `sendToall()` method (marked as "not used") distributes to every member without exclusions. Both methods leverage the `Client::enqueueIrcMessage()` interface to add formatted messages to each recipient's output buffer. This architecture enables efficient batch message delivery for operations like user joins, parts, topic changes, and regular chat messages, where a single event must notify multiple participants. The broadcasting abstraction centralizes message distribution logic, ensuring consistent delivery semantics across different command implementations.

#### Construction Patterns and Static Resources

The class provides multiple construction options: a default constructor initializing an unnamed channel with permissive defaults, a string-based constructor for direct name assignment, and a `ChanName`-based constructor (marked "not in use") that would leverage the validated channel name type. Default initialization establishes sensible starting values: all mode flags false, empty topic and key, zero limit, and empty member collections. The copy constructor and assignment operator provide deep copying of all state including member vectors, though the assignment operator includes defensive clearing of existing collections before copying—a pattern that seems redundant given vector assignment semantics but may reflect concern about state consistency. A static `IrcMM` instance (`_mm`) provides centralized access to message formatting capabilities, similar to the `Parser` class pattern, enabling consistent IRC message generation without per-channel message manager overhead.

---

### Server Class

#### Overview

The `Server` class represents the complete IRC server implementation, serving as the central orchestration point for all server operations. It manages the network listener socket, maintains collections of connected clients and active channels, coordinates message parsing and routing, and implements the core event loop using poll-based I/O multiplexing. As the highest-level component in the architecture, it integrates all previously described classes—`Client`, `Channel`, `Parser`, `IrcMM`, and the validation types—into a cohesive, functional IRC server capable of handling multiple simultaneous connections with non-blocking I/O.

#### Network Architecture and Socket Management

The server implements a non-blocking, event-driven network architecture using the `poll()` system call for I/O multiplexing. The `_listen` socket (wrapped in a `FileDescriptor` RAII object) accepts incoming connections on a configured port. The `setupListenSocket()` method creates this TCP socket, sets `SO_REUSEADDR` to prevent "address already in use" errors during rapid restarts, binds to `INADDR_ANY` (all network interfaces) on the specified port, and sets the socket to listening mode with maximum backlog. SIGPIPE signals are globally ignored through `ignoreSigpipeOnce()` to prevent server termination when clients unexpectedly close connections during writes—a design explicitly permitted by the project requirements. The `rebuildPollFds()` method dynamically reconstructs the poll file descriptor array before each `poll()` call, including the listen socket (always monitoring `POLLIN` for new connections) and all client sockets (monitoring `POLLIN` for incoming data, plus `POLLOUT` only when output buffers contain data awaiting transmission).

#### Event Loop and Non-Blocking I/O

The `run()` method implements the main event loop, calling `poll()` with infinite timeout to block until I/O events occur. When the listen socket becomes readable, `acceptLoop()` accepts new connections in a loop until `EAGAIN`, creating `Client` objects with IP address extraction via `getnameinfo()` (with fallback to `inet_ntop()` for IPv4). Client read events trigger `handleClientReadable()`, which receives data into the client's input buffer, extracts complete lines terminated by newline characters, strips IRC's CRLF line endings, and passes each complete command to the `Parser` for execution. Write events invoke `handleClientWritable()`, which sends queued data from the client's output buffer until either the buffer empties or the socket returns `EAGAIN` (indicating the kernel's send buffer is full). Error conditions (`POLLERR`, `POLLHUP`, `POLLNVAL`) or orderly disconnections (recv returns 0) trigger `dropClient()`, which removes the client from all channels with QUIT notification, deallocates the client object, and removes it from the clients list.

#### Registration and Authentication Flow

Client registration follows IRC's multi-step authentication protocol through the `tryRegister()` method, which is called after PASS, NICK, and USER commands. Registration requires sequential validation: first, `_passAccepted` must be true (matching the server's `_password`); second, a valid unique nickname must be set (checked against all registered clients to prevent collisions, returning `ERR_NICKNAMEINUSE` if duplicate); third, a valid username must be provided; finally, a hostname is ensured (defaulting to "localhost" if not captured during accept). Only when all conditions are met does the server mark the client as registered, broadcast a notification to existing users via `broadcastNotice()`, and send the welcome sequence including `RPL_WELCOME`, `RPL_MOTDSTART`, `RPL_MOTD`, and `RPL_ENDOFMOTD`. This staged approach prevents premature access to server features and ensures complete identity establishment before participation.

#### Channel Management and Message Routing

The server maintains a `std::map<std::string, Channel*>` associating channel names with channel objects. The `createChannel()` method implements lazy instantiation—checking for existence before creating new heap-allocated channels. The `findChannel()` method enables lookup operations, while `removeChannel()` enforces permissions (requiring channel operator status) before deletion. Channel lifecycle management includes `purgeChannels()`, which identifies and removes empty channels in a two-pass algorithm (preventing iterator invalidation). When clients disconnect, `leaveAllChannels()` removes them from all memberships, broadcasting QUIT messages to remaining channel members. Message routing splits between channel and private messages: `sendMessageToChannel()` validates channel membership before broadcasting to all members except the sender, while `sendPrivateMessage()` performs nickname lookup across the clients list and delivers directly to the target. The `listChannels()` family of methods (`listAllChannels()`, `listSingleChannel()`, `sendChannelUserList()`) provides various views of channel state, sending formatted `RPL_LIST`, `RPL_NAMREPLY`, and `RPL_ENDOFNAMES` responses through the `IrcMM` message manager.

#### Design Patterns and Resource Management

The class employs several sophisticated design patterns. Static members include the `IrcMM` message manager (shared formatting across all server instances) and are initialized outside the class definition. The `_parser` is heap-allocated with a reference to the server, enabling bidirectional communication—the parser calls server methods to execute commands, while the server invokes parser methods to process input. Clients and channels are stored as pointers in STL containers (`std::list<Client*>`, `std::map<std::string, Channel*>`), with the server owning these heap allocations and freeing them in the destructor. The client search pattern (`findClient()`, `findNick()`) uses iterators to safely identify targets, enabling subsequent operations like disconnection. Debug methods (`debugPrintClients()`, `debugChannels()`) provide runtime introspection. The architecture carefully handles edge cases: checking for client existence after potentially-destructive read operations (preventing use-after-free), using two-pass algorithms to avoid iterator invalidation during container modification, and defensive checking against NULL pointers and empty containers throughout.

---

## IRC Command Implementation Analysis

### Registration and Authentication Flow

The command implementations demonstrate a consistent authentication pattern that enforces IRC's registration requirements. Every command handler begins by checking `client->isRegistered()`, immediately returning an `ERR_NOTREGISTERED` error if false. This prevents unregistered clients from executing any IRC operations beyond the initial PASS/NICK/USER sequence. The registration check acts as a gatekeeper, ensuring that only authenticated, fully-identified clients can interact with channels or other users. This pattern appears universally across all command handlers (JOIN, KICK, INVITE, MODE, PRIVMSG), reflecting a fundamental security principle: identity must be established before participation is permitted.

### Parameter Validation and Error Handling

Each command implements rigorous parameter validation before attempting execution. The handlers check `_tokens.size()` against expected minimums, returning `ERR_NEEDMOREPARAMS` when insufficient arguments are provided. Complex commands like JOIN and KICK split comma-separated parameter lists using `_splitString()`, supporting IRC's compact syntax for multi-target operations (e.g., "JOIN #foo,#bar" or "KICK #chan user1,user2"). Validation occurs at multiple levels: first checking token counts, then attempting to construct validated type objects (`ChanName`, `NickName`) within try-catch blocks. When validation fails—whether from malformed channel names, invalid nicknames, or missing required parameters—specific error messages are enqueued to the client rather than causing server crashes. This defensive programming approach handles malformed input gracefully, a critical requirement for network-facing servers exposed to potentially malicious or buggy clients.

### Channel Permission Enforcement

The command implementations reveal a sophisticated permission hierarchy centered on channel operators (admins). KICK and MODE commands verify that the requesting client is a channel administrator through `_channelptr->isAdmin(client)`, returning `ERR_CHANOPRIVSNEEDED` if false. INVITE implements conditional permission checking: in invite-only channels (`isInviteOnly()`), only admins may invite; otherwise, any member can. The JOIN command enforces multiple access control mechanisms: checking invite-only status, validating channel keys, verifying user limits, and consulting the invited users list. MODE channel operations split into query mode (any member can view) and modification mode (only admins can change). This layered permission system implements IRC's social hierarchy, where channel creators and their appointed operators maintain control over channel properties while regular members have limited privileges.

### Message Broadcasting Patterns

The implementations demonstrate distinct message distribution strategies based on command semantics. KICK uses `sendToall()` to notify every channel member (including the kicker) of the removal, ensuring all participants observe the moderation action. JOIN broadcasts the join message to existing members via `broadcastMessage()` with the joining client excluded, then separately sends confirmation messages (topic, names list) directly to the joiner. INVITE operates privately—only the inviter and invitee receive notifications, unlike MODE changes which would typically broadcast. The KICK implementation correctly sequences operations: first formatting and distributing the KICK message to all members, then removing the kicked user from the channel's member list. This ordering ensures the kicked user receives their own KICK notification before disconnection, while other members see the event before the member list updates.

### Mode Management Complexity

The MODE command family showcases the implementation's most complex logic, splitting into user mode and channel mode handlers. The dispatcher attempts nickname construction first; on failure, it tries channel name construction, routing to the appropriate handler. Channel MODE supports both query operations (returning current mode strings via `getModes()`) and modification operations (requiring admin privileges). The mode parser handles compound mode strings like "+itk password" by iterating through flag characters and maintaining a parameter counter for flags requiring arguments (k for keys, l for limits). Most mode flags trigger `ERR_UMODEUNTREATED` responses, indicating they're recognized but unimplemented in this academic exercise—a pragmatic compromise that acknowledges protocol completeness while scoping implementation effort. The validation functions (`isValidUserModeString()`, `isValidChanModeString()`) enforce syntax rules, rejecting malformed mode strings before attempting application.

### JOIN Command Special Cases

The JOIN implementation handles IRC's special "JOIN 0" syntax, which requests leaving all channels simultaneously. Detecting this case early (`_tokens.size() == 2 && _tokens[1] == "0"`), the handler calls `leaveAllChannels()` followed by `purgeChannels()` to clean up empty channels. For normal joins, the command distinguishes between creating new channels (where the first joiner becomes admin automatically via `AddMember()`) and joining existing channels (requiring permission checks). The new channel path sets initial modes if keys are provided, while the existing channel path implements a complex decision tree: checking membership status, invite-only restrictions, user limits, and key requirements. The careful sequencing of `AddMember()`, message formatting via `IrcMM`, and broadcasting ensures proper state updates and notification delivery. Comments in the code reveal iterative refinement—multiple message format approaches commented out, suggesting evolution toward the current `Fmt_RPL_JOIN()` pattern that leverages centralized message management.



## VIM commands used to extract data from RFC2812
### step 1: Remove empty lines. (`:g/^$/d`)
```c++
   PASS: Establece la contraseña para la conexión.
     
   NICK: Define o cambia el apodo del usuario.
    
   USER: Especifica el nombre de usuario e información real.

   OPER: Autentica al usuario como operador IRC.
        
   QUIT: Cierra la conexión.
        
   PONG: Respuesta a un comando PING.
        
   PING: Verifica si la conexión está activa.
```
    
### step 2: Substitute command comments by `" ;` . (`:% s/:.*\./" ;/g`)


```c++
   PASS: Establece la contraseña para la conexión.
   NICK: Define o cambia el apodo del usuario.
   USER: Especifica el nombre de usuario e información real.
   OPER: Autentica al usuario como operador IRC.
   QUIT: Cierra la conexión.
   PONG: Respuesta a un comando PING.
   PING: Verifica si la conexión está activa.
```

### Step 3; Substitute leading spaces with type string (`:%s/^\s*/std::string "/`)

```c++
     PASS" ;
     NICK" ;
     USER" ;
     OPER" ;
     QUIT" ;
     PONG" ;
     PING" ;
```
### Step 4: create the name for the token variable  (`:% s/"\(\w\+\)"/token_\L\1 = "\U\1"/g`)


```c++
std::string "PASS" ;
std::string "NICK" ;
std::string "USER" ;
std::string "OPER" ;
std::string "QUIT" ;
std::string "PONG" ;
std::string "PING" ;
```

#### Final result
```c++
std::string token_pass = "PASS" ;
std::string token_nick = "NICK" ;
std::string token_user = "USER" ;
std::string token_oper = "OPER" ;
std::string token_quit = "QUIT" ;
std::string token_pong = "PONG" ;
std::string token_ping = "PING" ;
```


### Step5  Transform token's list into a nexted if as parser backbone

#### Substitute string declaration by `else if ....` (`:% s/std::string/ else if (tokens[0] == /g`)

```c++
else if (tokens[0] ==  token_pass = "PASS" ;
else if (tokens[0] ==  token_nick = "NICK" ;
else if (tokens[0] ==  token_user = "USER" ;
else if (tokens[0] ==  token_oper = "OPER" ;
else if (tokens[0] ==  token_quit = "QUIT" ;
else if (tokens[0] ==  token_pong = "PONG" ;
else if (tokens[0] ==  token_ping = "PING" ;
```
#### Substitute value asignation by then clause (`:% s/ = ".*/) {cmd_xxx(tokens);}/g`)

```c++
else if (tokens[0] ==  token_pass) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_nick) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_user) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_oper) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_quit) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_pong) {cmd_xxx(tokens);}
else if (tokens[0] ==  token_ping) {cmd_xxx(tokens);}
```

#### Capture token type and customize function name (` s/token_\(.*\)) {cmd_xxx/token_\1) {cmd_\1/g `)

```c++
else if (tokens[0] ==  token_pass) {cmd_pass(tokens);}
else if (tokens[0] ==  token_nick) {cmd_nick(tokens);}
else if (tokens[0] ==  token_user) {cmd_user(tokens);}
else if (tokens[0] ==  token_oper) {cmd_oper(tokens);}
else if (tokens[0] ==  token_quit) {cmd_quit(tokens);}
else if (tokens[0] ==  token_pong) {cmd_pong(tokens);}
else if (tokens[0] ==  token_ping) {cmd_ping(tokens);}
```


# rfc2812

### Replies


|messages | substitutions |
|---------|---------------|
|31       | 0|
|54       | 1|
|31       | 2|
| 9       | 3|
| 7       | 4|
| 1       | 6|
| 4       | 7|
|137      |messages |

#### Different substitution tags for the 54 messages
```yml
|<admin info>|
|<channel>|
|<channel name>|
|<command>|
|<config file>|
|<date>|
|<integer>|
|<mask>|
|<name>|
|<nick>|
|<nick/channel>|
|<nickname>|
|<server>|
|<server name>|
|<service name>|
|<servicename>|
|<stats letter>|
|<string>|
|<text>|
|<user>|
|<user mode string>|
```



#### Different duples of substitution tags for the 31 messages

```yml
|<channel><banmask>|
|<channel><char>|
|<channel><exceptionmask>|
|<channel><invitemask>|
|<channel><nick>|
|<channel><nickname>|
|<channel><topic>|
|<char><channel>|
|<class><client IP address in dot form>|
|<class><count>|
|<class><nick>|
|<class><server>|
|<file op><file>|
|<hostmask><name>|
|<integer><integer>|
|<logfile><debug level>|
|<mask><type>|
|<newtype><client name>|
|<nick><away message>|
|<nick><channel>|
|<nick><integer>|
|<nick><nick>|
|<reply><reply>|
|<server name><port number>|
|<servername><ver>|
|<server name><version & debug level>|
|<server><string showing server's local time>|
|<user><channel>|

```

#### Different truples of substitution tags for the 9 messages

```yml
|<channel><mode><mode params>|
|<channel><nick><nick>|
|<channel><# visible><topic>|
|<integer><integer><integer>|
|<nick><server><server info>|
|<nick><user><host>|
|<target><error code><abort message>|
|<username><ttyline><hostname>|
```

#### Different Cuadruples of substitution tags for the 7 messages

```yml
|<class><name><type><active type>|
|<command><count><byte count><remote count>|
|<mask><server><hopcount><server info>|
|<nick><user><host><real name>|
|<servername><version><available user modes><available channel modes>|
|<version><debuglevel><server><comments>|
```


#### Different Sextuples of substitution tags for the 1 message1

```yml
|<name><server><mask><type><hopcount><info>|
```


#### Different Septuples of substitution tags for the 4 messages

```yml
|<channel><user><host><server><nick><hopcount><real name>|
|<class><int><int><server><nick!user|*!*><host|server><protocol version>|
|<linkname><sendq><sent messages><sent Kbytes><received messages><received Kbytes><time open>|
|<version & debug level><destination><next server><protocol version><link uptime in seconds><backstream sendq><upstream sendq>|
```


### HostNames

```bnf
   host        =  hostname / hostaddr
   hostname    =  shortname *( "." shortname )
   shortname   =  ( letter / digit ) *( letter / digit / "-" )
                *( letter / digit )
                  ; as specified in RFC 1123 [HNAME]
   hostaddr    =  ip4addr / ip6addr
   ip4addr     =  1*3digit "." 1*3digit "." 1*3digit "." 1*3digit
   ip6addr     =  1*hexdigit 7( ":" 1*hexdigit )
   ip6addr     =/ "0:0:0:0:0:" ( "0" / "FFFF" ) ":" ip4addr

 ``` 
```C++
 bool HostName::validate(const std::string& s) const {
    if (s.length() > 63) {
        return false;
    }
    return isHostname(s) || isIp4addr(s) || isIp6addr(s);
}
```

### NickNames


```bnf
   nickname   =  ( letter / special ) *8( letter / digit / special / "-" )
   letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
   digit      =  %x30-39                 ; 0-9
   special    =  %x5B-60 / %x7B-7D
                   ; "[", "]", "\", "`", "_", "^", "{", "|", "}"
```                   

```C++
void NickName::validate(const std::string& name) const {
    if (name.length() != 9) {
        throw std::invalid_argument("NickName debe tener exactamente 9 caracteres.");
    }
    if (!isValidCharacter(name[0], true)) {
        throw std::invalid_argument("El primer caracter debe ser una letra o un caracter especial.");
    }
    for (size_t i = 1; i < name.length(); ++i) {
        if (!isValidCharacter(name[i], false)) {
            throw std::invalid_argument("Los caracteres siguientes deben ser una letra, digito, caracter especial o guion.");
        }
    }
}
```

