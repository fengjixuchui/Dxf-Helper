#pragma once

static int createRandom(int min, int max)
{
	int ����� = 0;
	if (max > min) {
		srand((unsigned)time(NULL));
		����� = (rand() % (min - max + 1) + max);
	}
	else {
		srand((unsigned)time(NULL));
		����� = (rand() % (max - min + 1) + min);
	}
	return �����;
}

// ��ȡʱ���
static DWORD getTime()
{
	DWORD t_start;
	t_start = GetTickCount();//�Ӳ���ϵͳ������������elapsed���ĺ����������ķ���ֵ��DWORD��
	return  t_start;
}

static POINT getMouseCoord()
{
	POINT Coord;
	if (GetCursorPos(&Coord)) {
		//printf("getMouseCoord Erro!\n");
	}
	return Coord;
}

static BOOL setMouseCoord(INT x, INT y)
{
	BOOL result;
	result = SetCursorPos(x, y);
	if (result == FALSE) {
		//printf("setMouseCoord Erro!\n");
	}
	return result;
}

static VOID mouseClick()
{
	MouseEvent(MOUSEEVENTF_LEFTDOWN or MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

static VOID mouseDoubleClick()
{
	MouseEvent(MOUSEEVENTF_LEFTDOWN or MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	MouseEvent(MOUSEEVENTF_LEFTDOWN or MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

static bool getKeyStatus(INT keyCode)
{
	if (GetKeyState(keyCode) < 0) {
		return TRUE;
	}
	return FALSE;
}

static INT getSCan(INT keyCode)
{
	INT sCan = MapVirtualKey(keyCode, 0);
	if (
		keyCode == VK_LEFT ||
		keyCode == VK_RIGHT ||
		keyCode == VK_DOWN ||
		keyCode == VK_UP
		)
	{
		sCan += 0x80;
	}
	return sCan;
}

static VOID keyDown(INT keyCode)
{
	KeybdEvent(keyCode, 0, 0, 0);
}

static VOID keyUp(INT keyCode)
{
	KeybdEvent(keyCode, 0, KEYEVENTF_KEYUP, 0);
}

static VOID doKeyPress(INT keyCode, INT s = 0)
{
	keyDown(keyCode);
	Sleep(s + createRandom(1, 10));
	keyUp(keyCode);
}

static void main_thread_exec_call(LPVOID pfun, std::vector<int> params = { 0 })
{
	DWORD_PTR *call_params = new DWORD_PTR[params.size()];
	for (size_t i = 0; i < params.size(); i++)
	{
		call_params[i] = params[i];
	}
	//SendMessage(g_hWnd, __MY_MESSAGE_ID, (WPARAM)pfun, (LPARAM)call_params);
	delete[]call_params;
}

// ��ɫ
static inline void cyan_print(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ����ɫ���
	va_list argList;
	char buffer[0x1024];
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}
//��ɫ
static inline void yellow_print(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//���ú�ɫ����ɫ���

	va_list argList;
	char buffer[0x1024];
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}
//��ɫ
static inline void pink_print(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//���ú�ɫ����ɫ���
	va_list argList;
	char buffer[0x1024];
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}
//��ɫ
static inline void red_print(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
	va_list argList;
	char buffer[0x1024];
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}
// ��ɫ
static inline void green_print(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
	va_list argList;
	char buffer[0x1024];
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

static inline void window_initialize()
{
	RECT rect;
	int cx, cy;
	int width, height;
	cx = GetSystemMetrics(SM_CXFULLSCREEN);
	cy = GetSystemMetrics(SM_CYFULLSCREEN);
	HWND g_self_window_handle = GetConsoleWindow();
	GetWindowRect(g_self_window_handle, &rect);
	MoveWindow(g_self_window_handle, 0, 0, 800, 600, TRUE);
	GetWindowRect(g_self_window_handle, &rect);
	width = (rect.right - rect.left);
	height = (rect.bottom - rect.top);
	MoveWindow(g_self_window_handle, cx - width, cy - height, width, height, TRUE);

	EnableMenuItem(GetSystemMenu(g_self_window_handle, FALSE), SC_CLOSE, MF_GRAYED);

	SetConsoleTitle(_T("ؼ"));
	//SetLayeredWindowAttributes(g_self_window_handle, 0, 200, 3);//͸��������
}

static inline void unload_driver(const char *driver_name)
{
	std::string ֹͣ����(driver_name);
	std::string ж������(driver_name);
	ֹͣ���� = "sc.exe stop " + ֹͣ����;
	ж������ = "sc.exe delete " + ж������;

	WinExec(ֹͣ����.c_str(), SW_HIDE);
	WinExec(ж������.c_str(), SW_HIDE);
}

static inline HANDLE load_driver(const char *path, const char *derver_name)
{
	DWORD dwRtn;
	BOOL bRet = FALSE;
	SC_HANDLE schSCManager = NULL;//SCM�������ľ��
	SC_HANDLE schService = NULL;//NT��������ķ�����
	HANDLE driver_handle = NULL;

	std::string ����������(derver_name);
	���������� = "\\\\.\\" + ����������;

	schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (schSCManager == NULL)
	{
		red_print("OpenSCManager() Faild %d ! \n", GetLastError());
		system("pause");
		exit(0);
	}
	schService = CreateServiceA(
		schSCManager,
		derver_name,
		derver_name,
		SERVICE_ALL_ACCESS,
		SERVICE_KERNEL_DRIVER,
		SERVICE_DEMAND_START,
		SERVICE_ERROR_NORMAL,
		path,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL
	);
	if (schService == NULL) {
		dwRtn = GetLastError();
		if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_EXISTS)
		{
			//��������ԭ�򴴽�����ʧ��
			red_print("��������ԭ�򴴽�����ʧ�� %d ! \n", dwRtn);
			unload_driver(derver_name);
			system("pause");
			exit(0);
		}

		// ���������Ѿ����أ�ֻ��Ҫ�� 
		schService = OpenServiceA(schSCManager, derver_name, SERVICE_ALL_ACCESS);
		if (schService == NULL)
		{
			//����򿪷���Ҳʧ�ܣ�����ζ����
			red_print("����򿪷���Ҳʧ�ܣ�����ζ���� ! \n");
			system("pause");
			exit(0);
		}
	}
	bRet = StartService(schService, NULL, NULL);
	if (!bRet)
	{
		DWORD dwRtn = GetLastError();
		if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_ALREADY_RUNNING)
		{
			red_print("StartService() Faild %d ! \n", dwRtn);
			system("pause");
			exit(0);
		}
		else
		{
			if (dwRtn == ERROR_IO_PENDING)
			{
				//�豸����ס
				red_print("StartService() Faild ERROR_IO_PENDING ! \n");
				system("pause");
				exit(0);
			}
			
		}
	}
	CloseServiceHandle(schService);

	//red_print("%ws", ����������.c_str());

	driver_handle = CreateFileA(
		����������.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		0,
		OPEN_EXISTING,
		0,
		0
	);

	if (driver_handle == INVALID_HANDLE_VALUE)
	{
		red_print("�����������ʧ�� hDriver %p Error Code <%d>\n ", driver_handle, GetLastError());
	}

	return driver_handle;
}

static inline void file_protect(const char * file_path,bool toggle)
{
	std::string str(file_path);
	if (toggle = true)
	{
		str = "cacls \"" + str + "\" /e /p everyone:n ";
	}
	else {
		str = "cacls \"" + str + "\" /e /p everyone:f ";
	}
	WinExec(str.c_str(), SW_HIDE);
}

static inline bool EnableDebugPrivilege(bool bEnable)
{
	//VMProtectBeginUltra("EnableDebugPrivilege");
	//Enabling the debug privilege allows the application to see 
	//information about service application
	BOOL fOK = false;     //Assume function fails
	HANDLE hToken;
	//Try to open this process's acess token
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		//Attempt to modify the "Debug" privilege
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
		fOK = (GetLastError() == ERROR_SUCCESS);
		CloseHandle(hToken);
	}
	//VMProtectEnd();
	return fOK;
}

static inline bool delete_self_file()
{
	//VMProtectBeginUltra("ɾ������");
	bool result = true;
	wchar_t FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//��ȡ�ļ�·��
	GetModuleFileName(NULL, FileName, MAX_PATH);
	wchar_t *NewFileName;
	NewFileName = new wchar_t[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//�����ļ�����
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_NORMAL);
	//����ֱ��ɾ��
	if (DeleteFile(FileName))//��ֱ��ɾ�����
	{
		delete[] NewFileName;
		return false;
	}
	//����APIһ�������ن���
	wsprintf(NewFileName, _T("C:\\Windows\\%C\0"), FileName[0]);
	CreateDirectory(NewFileName, NULL);
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf(NewFileName, _T("C:\\Windows ����������\0"), FileName[0], GetTickCount());
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile(NewFileName);
	if (!MoveFileEx(FileName, NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		//printf("ɾ������ʧ�� Error Code\n");
		return false;//�����˾ͷ���
	}
	MoveFileEx(NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes(NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	if (result == false)
	{
		printf("ɾ������ʧ�� Error Code\n");
		system("pause");
		exit(0);
	}
	//VMProtectEnd();
	return result;
}