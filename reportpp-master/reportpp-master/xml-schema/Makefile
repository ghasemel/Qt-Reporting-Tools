# TODO integrate this workflow into cmake configuration

OUTPUT_DIR=src/reportpp/parser
XSD_EXECUTABLE=xsdcxx

.PHONY: cxx-parser
cxx-parser: reportpp.xsd types.map ${OUTPUT_DIR}
	${XSD_EXECUTABLE} cxx-parser \
		--std c++11 \
		--generate-validation \
		--output-dir ${OUTPUT_DIR} \
		--generate-inline \
		--root-element-first \
		--type-map types.map \
		--namespace-map https://github.com/mmickey/reportpp=reportpp \
		reportpp.xsd

.PHONY: cxx-test
cxx-test: clean reportpp.xsd types.map ${OUTPUT_DIR}
	${XSD_EXECUTABLE} cxx-parser \
		--std c++11 \
		--generate-validation \
		--output-dir ${OUTPUT_DIR} \
		--generate-print-impl \
		--generate-inline \
		--root-element-first \
		--generate-test-driver \
		--type-map types.map \
		--namespace-map https://github.com/mmickey/reportpp=reportpp \
		reportpp.xsd

${OUTPUT_DIR}:
	mkdir -p ${OUTPUT_DIR}

.PHONY: clean
clean:
	rm -fr ${OUTPUT_DIR}
