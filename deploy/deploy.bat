
echo ������ȡ osgEarthX_COM ... ...
xcopy ..\projects\osgEarthX_COM\bin\*.dll .\ /s /y /d
del .\*_COMLib.dll

echo ������ȡ osgEarthX_Web ... ... 
xcopy ..\projects\osgEarthX_Web\build\bin\osgEarthX_Web*.dll /s /y /d