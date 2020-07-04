Name:           qt5-kdreports
Version:        1.7.1
Release:        1
Summary:        A Qt library for creating printable reports
Source:         %{name}-%{version}.tar.gz
URL:            http://github.com/KDAB/KDReports
Group:          System/Libraries
License:        GPL-2.0+
BuildRoot:      %{_tmppath}/%{name}-%{version}-build
Vendor:         Klaralvdalens Datakonsult AB (KDAB)
Packager:       Klaralvdalens Datakonsult AB (KDAB) <info@kdab.com>

BuildRequires: cmake
%if %{defined suse_version}
BuildRequires:  libqt5-qtbase-devel
%endif

%if %{defined fedora}
BuildRequires:  gcc-c++ qt5-qtbase-devel desktop-file-utils
%endif

%if %{defined rhel}
BuildRequires:  gcc-c++ qt5-qtbase-devel desktop-file-utils
%endif

%description
KDAB's KD Reports is the Qt tool that lets you easily create printable reports
by providing all of the necessary features for a variety of applications.

Authors:
--------
      Klaralvdalens Datakonsult AB (KDAB) <info@kdab.com>

%package devel
Summary:        Development files for %{name}
Group:          Development/Libraries/C and C++
Requires:       %{name} = %{version}

%description devel
This package contains header files and associated tools and libraries to
develop programs using kdreports.

%prep
%setup -q

%build
touch .license.accepted
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
%__make %{?_smp_mflags}

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%install
%make_install

%clean
%__rm -rf "%{buildroot}"

%files
%defattr(-,root,root)
%{_prefix}/share/doc/KDReports
%{_libdir}/libkdreports.so.*

%files devel
%defattr(-,root,root,-)
%dir %{_includedir}/KDReports
%{_includedir}/KDReports/*
%dir %{_libdir}/cmake/KDReports
%{_libdir}/cmake/KDReports/*
%{_libdir}/libkdreports.so

%changelog
* Thu Aug 11 2016 Allen Winter <allen.winter@kdab.com> 1.7.1
  1.7.1 final
