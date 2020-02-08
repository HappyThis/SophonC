
#pragma once

enum Token
{
	TokenExist,

	LocalIoRead,

	LocalIoWrite,

	LocalIoEndThread,

	TokenLogin,

	TokenHeartBeat,

	CommandRemoteCapture,

	TokenCaptureNewChange,

	CommandOpenNetworkServer,

	CommandCloseNetworkServer,

	CommandGetIp,

	CommandGetIo,

	CommandGetProtocol,


	CommandOpenFileDir,

	CommandOpenDoucmentFuntion,

	CommandCloseDoucmentFuntion,

	CommandExpandDir,

	CommandConfirmPath,

	CommandListen,

	CommandConnect,

	TokenNewStdOutput,

	CommandNewStdInput,

	CommandOpenCmd,

	CommandCloseCmd,
	
	CommandGetDir,

	CommandGetFiles,

	CommandNewFile,

	CommandNewFileName,

	CommandNewFilePath,

	CommandFathersIp,

	CommandReadyToListen,

	CommandReadyToConnect,

	TokenFinish,

	CommandRedirectIp,

	CommandGetOnlineInfo

};



