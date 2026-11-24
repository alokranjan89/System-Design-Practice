
#include <iostream>
#include <string>

// Target: interface expected by the client.
class IReportProvider {
public:
    virtual std::string getJson(const std::string& name,
                                const std::string& id) const = 0;
    virtual ~IReportProvider() = default;
};

// Adaptee: existing class with an incompatible interface.
class XmlDataProvider {
public:
    std::string getXml(const std::string& name,
                       const std::string& id) const {
        return "<user><name>" + name +
               "</name><id>" + id + "</id></user>";
    }
};

// Adapter: IS-A IReportProvider and HAS-A XmlDataProvider.
class XmlReportAdapter : public IReportProvider {
private:
    const XmlDataProvider& provider;

    static std::string readTag(const std::string& xml,
                               const std::string& tag) {
        const std::string open = "<" + tag + ">";
        const std::string close = "</" + tag + ">";

        const size_t start = xml.find(open);
        if (start == std::string::npos) {
            return "";
        }

        const size_t valueStart = start + open.size();
        const size_t end = xml.find(close, valueStart);
        if (end == std::string::npos) {
            return "";
        }

        return xml.substr(valueStart, end - valueStart);
    }

public:
    explicit XmlReportAdapter(const XmlDataProvider& adaptee)
        : provider(adaptee) {}

    std::string getJson(const std::string& name,
                        const std::string& id) const override {
        const std::string xml = provider.getXml(name, id);
        const std::string xmlName = readTag(xml, "name");
        const std::string xmlId = readTag(xml, "id");

        return "{\"name\":\"" + xmlName +
               "\",\"id\":\"" + xmlId + "\"}";
    }
};

// Client: uses only the Target abstraction.
class ReportClient {
public:
    void printReport(const IReportProvider& provider,
                     const std::string& name,
                     const std::string& id) const {
        std::cout << provider.getJson(name, id) << '\n';
    }
};

int main() {
    XmlDataProvider xmlProvider;
    XmlReportAdapter adapter(xmlProvider);
    ReportClient client;

    client.printReport(adapter, "Alok", "101");
    return 0;
}
