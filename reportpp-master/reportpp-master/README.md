reportpp
========

XML based C++ library for report generation
-------------------------------------------

This library wants to simplify the generation of PDF reports. The configuration
for report pages is intended to be in a XML file that instruct the library on
things like page header/footer, margins, cover page, etc.

This allow the user to edit the configuration (manually or throug an automated
interface tool, not planned at the moment), and so to create different looking
reports based on its needs.

Dependencies
------------
Actually the only choice made is to use the haru library (http://libharu.org)
as a base for PDF generation.

The `xsdcxx` tool by codesynthesis (http://codesynthesis.com/projects/xsd) is
used to generate XML config file parser.
