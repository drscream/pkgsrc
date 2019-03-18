$NetBSD$

--- SecureSkat_misc.cc.orig	2018-06-13 14:36:11.000000000 +0000
+++ SecureSkat_misc.cc
@@ -29,7 +29,7 @@ int BindEmptyPort
 	while (current_port < (start_port + max_ports))
 	{
 		int sockfd;
-		long socket_option = 1;
+		int socket_option = 1;
 		struct sockaddr_in sin = { 0 };
 		sin.sin_port = htons(current_port);
 		sin.sin_family = AF_INET;
@@ -75,7 +75,7 @@ int ListenToPort
 	(int port)
 {
 	int sockfd;
-	long socket_option = 1;
+	int socket_option = 1;
 	struct sockaddr_in sin = { 0 };
 	sin.sin_port = htons(port);
 	sin.sin_family = AF_INET;
