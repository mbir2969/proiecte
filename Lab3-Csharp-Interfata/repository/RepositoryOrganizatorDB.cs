using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data;
using Lab3.model;
using log4net;
using tasks.repository;

namespace Lab3.repository
{

    public class RepositoryOrganizatorDB :RepositoryOrganizator
    {
        private static readonly ILog logger = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        IDictionary<String, string> props;

        public RepositoryOrganizatorDB(IDictionary<string, string> props)
        {
            logger.InfoFormat("Initializing repository organizatori task.");
            this.props = props;
        }

        public void add(Organizator elem)
        {
            logger.InfoFormat("Saving task: {0}.", elem.ToString());
            var connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "insert into Organizatori (username, password) values (@username, @password)";
                var paramUsername = command.CreateParameter();
                paramUsername.ParameterName = "@username";
                paramUsername.Value = elem.getUserName();
                command.Parameters.Add(paramUsername);

                var paramPassword = command.CreateParameter();
                paramPassword.ParameterName = "@password";
                paramPassword.Value = elem.getPassword();
                command.Parameters.Add(paramPassword);
                
                var result = command.ExecuteNonQuery();
                logger.InfoFormat("Saved {0} instances.", result);   

            }
            logger.InfoFormat("{0} was saved.", elem.ToString());
        }

        public void delete(int id)
        {
            logger.InfoFormat("Deleting task {0}.", id.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "delete from Organizatori where id=@id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);
                var result = command.ExecuteNonQuery();
                
                logger.InfoFormat("Deleted {0} instances.", result);
            }
            logger.InfoFormat("Instance with id: {0} was deleted.",id.ToString());
        }

        public void update(Organizator elem, int id)
        {
            logger.InfoFormat("Updating task {0}.", elem.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "update Organizatori set username = @username, password = @password where id = @id";
                IDbDataParameter paramUsername = command.CreateParameter();
                paramUsername.ParameterName = "@username";
                paramUsername.Value = elem.getUserName();
                command.Parameters.Add(paramUsername);
                
                IDbDataParameter paramPassword = command.CreateParameter();
                paramPassword.ParameterName = "@password";
                paramPassword.Value = elem.getPassword();
                command.Parameters.Add(paramPassword);

                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                var result = command.ExecuteNonQuery();
                
                logger.InfoFormat("Updated {0} instances.", result);
            }

            logger.InfoFormat("Instance {0} was updated.",elem.ToString());
        }

        public Organizator findById(int id)
        {
            logger.InfoFormat("Finding one task.");
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Organizatori where id = @id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                using (var result = command.ExecuteReader())
                {
                    if (result.Read())
                    {
                        String username = result.GetString(1);
                        String password = result.GetString(2);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(id);
                        logger.InfoFormat("Instance with id {0} was found.",id.ToString());
                        return organizator;
                    }
                }
            }
            logger.InfoFormat("No instance with id {0} was found.", id.ToString());
            return null;
        }

        public IEnumerable<Organizator> findAll()
        {
            logger.InfoFormat("Finding all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            IList<Organizator> organizatori = new List<Organizator>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Organizatori";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        String username = result.GetString(1);
                        String password = result.GetString(2);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(id);
                        organizatori.Add(organizator);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", organizatori.Count.ToString());
            return organizatori;
        }

        public Collection<Organizator> getAll()
        {
            logger.InfoFormat("Getting all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            Collection<Organizator> organizatori = new Collection<Organizator>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Organizatori";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        String username = result.GetString(1);
                        String password = result.GetString(2);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(id);
                        organizatori.Add(organizator);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", organizatori.Count.ToString());
            return organizatori;
        }
    }
}