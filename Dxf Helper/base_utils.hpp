#pragma once


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

	SetConsoleTitle(_T(""));
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

