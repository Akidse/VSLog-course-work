enum text
{
	LOGIN_SUCCESS,
	LOGIN_FAIL,
	START_PAGE,
	HELP,
	WRONG_COMMAND,
	ADD_USER_SUCCESS,
	ADD_USER_FAIL,
	ADD_USER_ERR_PASS,
	ADD_USER_EXISTED,
	CHANGE_PASS_SUCCESS,
	USER_NOT_EXIST,
	USER_CANT_DELETE_HIMSELF,
	USER_DELETE_SUCCESS,
	USER_DELETE_FAIL,
	NOT_ALLOWED,
	GROUP_NOT_FOUND,
	GROUP_CANT_CREATE,
	GROUP_CREATED_SUCCESS
};

std::string get_message(text msg)
{
	std::string message;
	switch(msg)
	{
	case LOGIN_SUCCESS:
		message = "Login successfull";
		break;
	case LOGIN_FAIL:
		message = "You enter bad login data";
		break;
	case START_PAGE:
		message = "Login successfull\r\n Welcome to VSLOG v.1.0.\r\n It is the most easier visiting college log!";
		break;
	case HELP:
		message = "This is help manual for using VSLog:\r\n-help -- help manual \r\n -clear -- clear window \r\n -adduser -- add new user \r\n -pass -- change your pass \r\n -users -- get list of users \r\n -userdel -- delete user \r\n -today -- display today's date";
		break;
	case WRONG_COMMAND:
		message = "You wrote wrong command. Tap -help for information about commands.";
		break;
	case ADD_USER_SUCCESS:
		message = "User added successfully";
		break;
	case ADD_USER_FAIL:
		message = "Can't create user file.";
		break;
	case ADD_USER_ERR_PASS:
		message = "Passwords are not the same.";
		break;
	case ADD_USER_EXISTED:
		message = "This user already exists";
		break;
	case CHANGE_PASS_SUCCESS:
		message = "Pass changed successfully";
		break;
	case USER_NOT_EXIST:
		message = "Such user do not exist";
		break;	
	case USER_CANT_DELETE_HIMSELF:
		message = "You can't delete your user data by yourself";
		break;
	case USER_DELETE_SUCCESS:
		message = "User was deleted successfull";
		break;	
	case USER_DELETE_FAIL:
		message = "Can't delete user";
		break;
	case NOT_ALLOWED:
		message = "You are not allowed to do this thing";
		break;
	case GROUP_NOT_FOUND:
		message = "Such group do not exists";
		break;
	case GROUP_CANT_CREATE:
		message = "Can't create group with such name";
		break;
	case GROUP_CREATED_SUCCESS:
		message = "Group created successfully";
		break;
	}

	return message;
}