#!/usr/bin/env python
from autogen.autogen import autogen

project = "KDReports"
version = "1.7.50"
subprojects = ["KDReports"]
prefixed = True

autogen(project, version, subprojects, prefixed, policyVersion = 2)
